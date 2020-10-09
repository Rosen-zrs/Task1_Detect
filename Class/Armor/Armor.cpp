#include "include/Armor.h"
#include "../Light/include/Light.h"
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include "math.h"

/**
 * @brief 装甲板构造函数
 * 
 * @param  left_light 左灯条类引用
 * @param  right_light 右灯条类引用
 * @param  center_dis 灯条中心距离
 * @return 无
 */
Armor::Armor(Light &left_light, Light &right_light, float center_dis)
{
    //定义公灯条矩形的4个顶点
    Point2f left_light_vertices[4];
    //定义母灯条的4个顶点  
    Point2f right_light_vertices[4]; 

    left_light.rect.points(left_light_vertices);
    right_light.rect.points(right_light_vertices);

    //初始化成员函数
    this->height = (left_light.get_height() + right_light.get_height()) / 2;
    this->width = abs(left_light.get_center().x - right_light.get_center().x) + left_light.get_width();
    this->lights[0] = left_light;
    this->lights[1] = right_light;
    this->center_dis = center_dis;
    this->p_bl = left_light_vertices[0];
    this->p_tl = left_light_vertices[1];
    this->p_tr = right_light_vertices[2];
    this->p_br = right_light_vertices[3];
    this->Area = this->height * this->width;
}

/**
 * @brief 获取装甲板的高度函数
 * 
 * @return 装甲板高度
 */
float Armor::get_height()
{
    return this->height;
}


/**
 * @brief 获取装甲板的宽度函数
 * 
 * @return 装甲板宽度
 */
float Armor::get_width()
{
    return this->width;
}


/**
 * @brief 获取装甲板灯条中心点距离
 * 
 * @return 装甲板灯条中心点距离
 */
float Armor::get_center_dis()
{
    return this->center_dis;
}

/**
 * @brief 获得装甲板左灯条
 * 
 * @return
 */
Light Armor::get_left_light()
{
    return this->lights[0];
}

/**
 * @brief 获取装甲板右灯条
 * 
 * @return
 */
Light Armor::get_right_light()
{
    return this->lights[1];
}

/**
 * @brief 获取装甲板面积
 * 
 * @return 
 */
float Armor::get_area()
{
    return this->Area;
}


/**
 * @brief 获取装甲板作左下角点
 * 
 * @return 
 */
Point2f Armor::bl()
{
    return this->p_bl;
}

/**
 * @brief 获取装甲板作左上角点
 * 
 * @return 
 */
Point2f Armor::tl()
{
    return this->p_tl;
}

/**
 * @brief 获取装甲板作右上角点
 * 
 * @return 
 */
Point2f Armor::tr()
{
    return this->p_tr;
}

/**
 * @brief 获取装甲板作右下角点
 * 
 * @return 
 */
Point2f Armor::br()
{
    return this->p_br;
}


/**
 * @brief 调整矩形角度和宽高
 * 
 * @param rect 旋转矩形
 * @return 变换后的矩形(RotatedRect)
 */
RotatedRect tranform_rect(RotatedRect &rect)
{
    float &width = rect.size.width;
    float &height = rect.size.height;
    float &angle = rect.angle;

    if (angle >= 90.0)
        angle -= 180.0;
    if (angle < -90.0)
        angle += 180.0;

    if (angle >= 45.0)
    {
        swap(width, height);
        angle -= 90.0;
    }
    else if (angle < -45.0)
    {
        swap(width, height);
        angle += 90.0;
    }

    return rect;
}