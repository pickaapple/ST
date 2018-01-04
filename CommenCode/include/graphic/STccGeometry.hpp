//
//  STccGeometry.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/22.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccGeometry_hpp
#define STccGeometry_hpp

#include "STccMacro.hpp"

NS_STCC_BEGIN

////////////////////////////////////////
//Size
struct Size2D
{
    double _width;
    double _height;
};

////////////////////////////////////////
//Point
struct Point2D
{
    double _x;
    double _y;
    
    Point2D operator + (const Point2D& point) const
    {
        return { point._x + _x , point._y + _y };
    }
    
    Point2D operator + (const Size2D& size) const
    {
        return { size._width + _x , size._height + _y };
    }
};

struct Point2I16
{
    int16_st _x;
    int16_st _y;
};

struct Point2I32
{
    int32_st _x;
    int32_st _y;
};

typedef Point2D Point;

//the orgin and the target should not be the same.
inline uint8_st ComparePoints(const Point2D& orign, const Point2D& target);

////////////////////////////////////////
//Rectangle
struct Rect
{
    Point2D _orign;
    Size2D  _size;
};

bool IfPointInRect(const Point& point, const Rect& rect);

////////////////////////////////////////
//Vecter
struct Vecter2D
{
    double _dx;
    double _dy;
};

struct Vecter3D
{
    double _dx;
    double _dy;
    double _dz;
};

////////////////////////////////////////
//Matrix
struct Matrix4D
{
public:
    void Set(double m11,double m12,double m13,double m14,
             double m21,double m22,double m23,double m24,
             double m31,double m32,double m33,double m34,
             double m41,double m42,double m43,double m44);
    
    void Set(const double* mat);
    
    void set(const Matrix4D& mat);
    
    void Translate(double x,double y,double z);
    
    void MultiplyMat(const Matrix4D *source);
    
    static void CreateTranslate(double x,double y,double z,Matrix4D *dst);
    
    static void CreateRotationX(double angle, Matrix4D* dst);
    
    static void CreateRotationY(double angle, Matrix4D* dst);
    
    static void CreateRotationZ(double angle, Matrix4D* dst);
    
    static void CreatePerspective(double left,double right,double top,double bottom,double znear,double zfar,Matrix4D *dst);
    
    static void CreatePerspective(double width,double height,double znear,double zfar,Matrix4D *dst);
    
    void Log();
    
    Matrix4D();
    
    /*
     *  m11  m12  m13  m14
     *  m21
     *  m31
     *  m41
     *
     */

    Matrix4D(double m11,double m12,double m13,double m14,
             double m21,double m22,double m23,double m24,
             double m31,double m32,double m33,double m34,
             double m41,double m42,double m43,double m44);
    
public:
    double _m[16];
    
    //      identity matrix4f
    //      1.0f,0.0f,0.0f,0.0f,
    //      0.0f,1.0f,0.0f,0.0f,
    //      0.0f,0.0f,1.0f,0.0f,
    //      0.0f,0.0f,0.0f,1.0f
    static const Matrix4D IDENTITY;
};

void MultiplyMatrix(const double* m1,const double* m2,double* dst);

NS_STCC_END

#endif /* STccGeometry_hpp */
