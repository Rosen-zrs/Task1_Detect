#include "Class/Armor/include/Armor.h"
#include "Class/Light/include/Light.h"
#include "Class/Energy_Switch/include/Energy_Switch.h"
#include "Class/Light/include/Match_Condition.h"
#include <iostream>
#include <math.h>
#include <time.h>

using namespace cv;
using namespace std;

#define DEBUG
#define PREDICT
#define BLUE
// #define ENERGY_SWITCH
#define ARMOR_DETECT

int main(int argc, char **argv)
{
    //导入视频
    VideoCapture capture(0);
    capture.open("/home/rosen/桌面/Rosen/Task1_Detect/Video/Armor1.mp4");

    if (!capture.isOpened())
    {
        printf("could not find video data file...\n");
        return -1;
    }

#ifdef DEBUG
    //创建窗口
    namedWindow("Origin", WINDOW_NORMAL);
    resizeWindow("Origin", Size(640, 480));

    // namedWindow("Video", WINDOW_NORMAL);
    // resizeWindow("Video", Size(640, 480));
    // moveWindow("Origin", 800, 90);
#endif // DEBUG

    //定义Mat变量
    Mat frame, src, bin_src, Temp1, Temp2, dst, result, img;

#ifdef ENERGY_SWITCH
    //能量开关模板匹配度
    double max1, max2;

    //load Template from image
    Temp1 = imread("/home/rosen/桌面/Rosen/RM/ES_Detect/p1.jpg", 0);
    Temp2 = imread("/home/rosen/桌面/Rosen/RM/ES_Detect/p2.jpg", 0);
#endif // ENERGY_SWITCH

    //分离RGB通道输出Mat数组
    Mat c_frame[3];

    //定义目标打击点
    Point2f center;

    //定义世界坐标和图像坐标
    vector<Point3d> World_Coor = {Point3f(0, 0, 0), Point3f(0, 26.5, 0), Point3f(67.5, 26.5, 0), Point3f(67.5, 0, 0)};

    //读取yml文件
    FileStorage fs2("/home/rosen/桌面/Rosen/Task1_Detect/cam/cam.yml", FileStorage::READ);
    Mat cameraMatrix2, distCoeffs2;
    fs2["camera_matrix"] >> cameraMatrix2;
    fs2["distortion_coefficients"] >> distCoeffs2;

#ifdef PREDICT
    //储存中心点和上一帧中心点信息
    Point2f pre_center(0, 0), predict_center;
    float dx, dy;

    //计算时间变量
    double start, end, dt;

    //定义相乘系数
    double factor = 250.0;
#endif // PREDICT

    while (capture.read(frame))
    {

#ifdef PREDICT
        //计算程序运行时间
        start = static_cast<double>(getTickCount()); //获取开始执行时间
#endif

        //分离图像RGB通道
        split(frame, c_frame);

#ifdef BLUE
        //蓝色通道 - 红色通道
        src = c_frame[0] - c_frame[2];
#else
        //红色通道 - 蓝色通道
        src = c_frame[2] - c_frame[0];
#endif // BLUE

#ifdef ENERGY_SWITCH
        GaussianBlur(src, src, Size(5, 5), 0);

        //二值化
        threshold(src, bin_src, 50, 255, THRESH_BINARY);

        //定义结构元素，进行闭操作
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
        dilate(bin_src, bin_src, element);
        morphologyEx(bin_src, bin_src, MORPH_CLOSE, element);

        // 查找轮廓
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(bin_src, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

        //定义矩形的4个顶点
        Point2f vertices[4];
        Point2f goal_rect[4];
        Moments mu;
        Point2f mc;

        for (size_t i = 0; i < contours.size(); i++)
        {
            if (contourArea(contours[i]) > 800)
            {
                RotatedRect rect = minAreaRect(contours[i]);
                //获得旋转矩形的四个角点
                rect.points(vertices);

                //创建能量开关类，并获得仿射变换矩形角点
                Energy_Switch es(vertices);

                //仿射变换
                dst = Affine(bin_src, es);

                //分别进行模板匹配
                matchTemplate(dst, Temp1, result, TM_CCOEFF_NORMED, Mat()); //模板匹配
                minMaxLoc(result, 0, &max1, 0, 0, Mat());                   //定位最匹配的位置
                matchTemplate(dst, Temp2, result, TM_CCOEFF_NORMED, Mat()); //模板匹配
                minMaxLoc(result, 0, &max2, 0, 0, Mat());                   //定位最匹配的位置

                if (max1 >= 0.65 || max2 >= 0.66)
                {
                    if (hierarchy[i][2] != -1)
                    {
                        //计算拓扑结构中子轮廓中心点
                        mu = moments(contours[hierarchy[i][2]], false);
                        mc = Point2f(mu.m10 / mu.m00, mu.m01 / mu.m00);

                        center = mc;

                        //标定目标点
                        circle(frame, center, 3, Scalar(255, 255, 255), -1, 8, 0);
                        circle(frame, center, 27, Scalar(255, 255, 255), 1, 8, 0);
                    }

                    // // draw retangle of the aim energy_switch
                    // for (int i = 0; i < 4; i++)
                    // line(frame, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 1);
                }
            }
        }

#endif // ENERGY_SWITCH

#ifdef ARMOR_DETECT
        //分离图像RGB通道
        split(frame, c_frame);

        //红蓝通道相减
        src = c_frame[0] - c_frame[2];

        //设定阈值二值化
        threshold(src, src, 60, 255, THRESH_BINARY);

        //膨胀
        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
        dilate(src, src, element);

        //提取轮廓
        vector<vector<Point>> contours;
        findContours(src, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());

        //定义外接拟合矩形
        RotatedRect rect;
        Point2f vertices[4]; //定义矩形的4个顶点

        //定义动态灯条数组
        vector<Light> lights;

        //定义匹配条件结构体
        Match_Condition MATCH_COND;

        bool flag = false;

        for (size_t i = 0; i < contours.size(); i++)
        {
            //筛除小轮廓(斑点)
            if (contourArea(contours[i]) < 80)
            {
                continue;
            }

            if (contours[i].size() > 5)
            {
                //椭圆拟合
                rect = fitEllipse(contours[i]);

                //调整矩形角度和宽高
                tranform_rect(rect);

                rect.points(vertices);

                float contour_area = contourArea(contours[i]);

                if (rect.size.width / rect.size.height > MATCH_COND.MAX_WH_RATIO || rect.size.height / rect.size.width > 4.5 || contour_area / rect.size.area() < MATCH_COND.MIN_AREA_FULL)
                    continue;

                // //太远的装甲板不选择打击
                // if ( rect.size.height / rect.size.width < 1.8)
                //     continue;

                //绘制矩形
                for (int i = 0; i < 4; i++)
                {
                    line(frame, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 1);
                }

                //配置灯条成员信息
                Light light = Light(rect, contourArea(contours[i]), arcLength(contours[i], true));
                light.rect = rect;
                lights.push_back(light);
            }
        }

        vector<Armor> Matching_Armor;

        //定义公灯条矩形的4个顶点
        Point2f left_light_vertices[4];
        //定义母灯条的4个顶点
        Point2f right_light_vertices[4];

        //匹配灯条
        for (auto left_light : lights)
        {
            for (auto right_light : lights)
            {
                if (left_light.get_center().x < right_light.get_center().x)
                {
                    //计算灯条特征逐步筛选

                    //面积差值
                    float area_ratio_diff = abs(left_light.get_area() - right_light.get_area());
                    if (area_ratio_diff > left_light.get_area() * MATCH_COND.MAX_AREA_DIFF && area_ratio_diff > right_light.get_area() * MATCH_COND.MAX_AREA_DIFF)
                        continue;

                    //宽度和高度差值
                    float height_diff = abs(left_light.get_height() - right_light.get_height());
                    if (height_diff > left_light.get_height() * MATCH_COND.MAX_HEIGHT_DIFF && height_diff > right_light.get_height() * MATCH_COND.MAX_HEIGHT_DIFF)
                        continue;

                    //角度差值
                    float angle_diff = abs(left_light.get_angle() - right_light.get_angle());
                    if (angle_diff > MATCH_COND.MAX_ANGLE_DIFF)
                        continue;

                    //中心距离差值
                    float center_dis_diff = distance(left_light.get_center(), right_light.get_center());
                    float center_y_diff = abs(left_light.get_center().y - right_light.get_center().y);
                    float center_x_diff = abs(left_light.get_center().x - right_light.get_center().x);

                    //根据中心距筛除
                    if (center_dis_diff < 3.5 * left_light.get_height() && center_y_diff < 0.8 * left_light.get_height() && center_x_diff > left_light.get_width())
                    {
                        Matching_Armor.push_back(Armor(left_light, right_light, center_dis_diff));
                    }
                }
            }
        }

        int min_index = 0;
        float min_dis, max_area;

//选择识别装甲板模式 --- solvePnP()姿态解算 --- 特征筛选 ---
// #define SOLVEPNP
#define FEATURE_SCREEN

        if (Matching_Armor.size() >= 1)
        {
            for (size_t i = 0; i < Matching_Armor.size(); i++)
            {
                //改变标志位
                flag = true;
#ifdef SOLVEPNP
                Mat rvec, tvec, R;

                //传入图像坐标
                vector<Point2d> Img_Coor;
                Img_Coor.push_back(Matching_Armor[i].bl());
                Img_Coor.push_back(Matching_Armor[i].tl());
                Img_Coor.push_back(Matching_Armor[i].tr());
                Img_Coor.push_back(Matching_Armor[i].br());

                //slovepnp姿态解算
                solvePnP(World_Coor, Img_Coor, cameraMatrix2, distCoeffs2, rvec, tvec);
                // Rodrigues(rvec, R);

                //挑选计算出距离最近的装甲板
                double Z = tvec.at<double>(2);

                //记录最近装甲板下标
                if (i == 0)
                {
                    min_dis = Z;
                    min_index = i;
                }
                if (Z < min_dis)
                {
                    min_dis = Z;
                    min_index = i;
                }

#endif // SOLVEPNP

#ifdef FEATURE_SCREEN

                float mean_area = (Matching_Armor[i].get_left_light().get_area() + Matching_Armor[i].get_right_light().get_area()) / 2;

                //记录灯条对最大面积
                if (i == 0)
                {
                    max_area = mean_area;
                }
                else
                {
                    if (mean_area > max_area)
                    {
                        max_area = mean_area;
                    }
                }

                //当面积与最大面积相近时，以中心矩离优先匹配
                if (flag)
                {
                    for (size_t j = 0; j < Matching_Armor.size(); j++)
                    {
                        if (j == 0)
                        {
                            min_dis = Matching_Armor[j].get_center_dis();
                        }
                        //计算灯条平均面积
                        float mean_area = (Matching_Armor[j].get_left_light().get_area() + Matching_Armor[j].get_right_light().get_area()) / 2;

                        if (abs(mean_area - max_area) / max_area < 0.15)
                        {
                            //匹配最近灯条对
                            if (Matching_Armor[j].get_center_dis() < min_dis)
                            {
                                min_dis = Matching_Armor[j].get_center_dis();
                                min_index = j;
                            }
                        }
                    }
                }
            }

#endif // FEATURE_SCREEN

            if (flag)
            {
                //取出目标装甲板及其灯条
                Light aim_left_light, aim_right_light;
                aim_left_light = Matching_Armor[min_index].get_left_light();
                aim_right_light = Matching_Armor[min_index].get_right_light();

                aim_left_light.rect.points(left_light_vertices);
                aim_right_light.rect.points(right_light_vertices);

                //绘制矩形
                for (int i = 0; i < 4; i++)
                    line(frame, left_light_vertices[i], left_light_vertices[(i + 1) % 4], Scalar(0, 0, 255), 2, 8, 0);
                for (int i = 0; i < 4; i++)
                    line(frame, right_light_vertices[i], right_light_vertices[(i + 1) % 4], Scalar(0, 0, 255), 2, 8, 0);

                //标定目标矩形
                line(frame, aim_left_light.rect.center, aim_right_light.rect.center, Scalar(255, 255, 255), 2, 8, 0);
                center = Point2f((aim_left_light.rect.center.x + aim_right_light.rect.center.x) / 2, (aim_left_light.rect.center.y + aim_right_light.rect.center.y) / 2);
                circle(frame, center, 7, Scalar(0, 0, 255), -1, 8, 0);
            }

#endif // ARMOR_DETECT

#ifdef PREDICT
            if (distance(center, pre_center) < Matching_Armor[min_index].get_width() / 2.0)
            {
                //求导进行预测
                dx = center.x - pre_center.x;
                dy = center.y - pre_center.y;

                //计算运行时间
                end = static_cast<double>(getTickCount());
                dt = (end - start) / getTickFrequency();

                //计算出预测中心点坐标
                predict_center = Point2f(center.x + factor * dx * dt, center.y + factor * dy * dt);
                circle(frame, predict_center, 7, Scalar(0, 255, 0), -1, 8, 0);
            }

            pre_center = center;
#endif // PREDICT
        }

#ifdef DEBUG
        //显示图像
        imshow("Origin", frame);
#endif // DEBUG

        if (waitKey(30) == 27)
        {
            if (waitKey(0) == 27)
            {
                break;
            }
        }
    }
}
