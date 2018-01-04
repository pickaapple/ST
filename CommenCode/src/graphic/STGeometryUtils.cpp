//
//  STccGeometry.cpp
//  STCommenCode
//
//  Created by yhys on 2017/8/22.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <math.h>
#include <string.h>

#include "graphic/STccGeometry.hpp"


uint8_st NS_STCC ComparePoints(const Point2D& orign, const Point2D& target)
{
    if(orign._x > target._x)
        return orign._y > target._y ? 1 : 4;
    else
        return orign._y > target._y ? 2 : 3;
}

bool NS_STCC IfPointInRect(const Point& point, const Rect& rect)
{
    uint8_st quadrantOfOrign = ComparePoints(point, rect._orign);
    uint8_st quadrantOfDiagonal = ComparePoints(point, rect._orign + rect._size);
    
    //the point should be in first quadrant of rect's orign and third quadrant of diagonal orign point
    //the point should be in third quadrant of rect's orign and first quadrant of diagonal orign point
    
    if(4 != quadrantOfOrign + quadrantOfDiagonal)
        return false;
    
    if(2 == quadrantOfOrign)
        return false;
    
    return true;
}

////////////////////////////////////////
//Matrix

NS_STCC Matrix4D::Matrix4D(){
    *this = IDENTITY;
}

NS_STCC Matrix4D::Matrix4D(double m11,double m12,double m13,double m14,double m21,double m22,double m23,double m24,double m31,double m32,double m33,double m34,double m41,double m42,double m43,double m44){
    Set(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}
void NS_STCC Matrix4D::Set(double m11,double m12,double m13,double m14,double m21,double m22,double m23,double m24,
                    double m31,double m32,double m33,double m34,double m41,double m42,double m43,double m44)
{
    _m[0]  = m11;
    _m[1]  = m21;
    _m[2]  = m31;
    _m[3]  = m41;
    _m[4]  = m12;
    _m[5]  = m22;
    _m[6]  = m32;
    _m[7]  = m42;
    _m[8]  = m13;
    _m[9]  = m23;
    _m[10] = m33;
    _m[11] = m43;
    _m[12] = m14;
    _m[13] = m24;
    _m[14] = m34;
    _m[15] = m44;
}

void NS_STCC Matrix4D::Set(const double* mat)
{
    ASSERT(mat);
    memcpy(this->_m,mat,sizeof(Matrix4D));
}

void NS_STCC Matrix4D::set(const Matrix4D& mat)
{
    memcpy(this->_m,mat._m,sizeof(Matrix4D));
}

void NS_STCC Matrix4D::Translate(double x,double y,double z){
    Matrix4D tran;
    CreateTranslate(x, y, z, &tran);
    MultiplyMat(&tran);
}

void NS_STCC Matrix4D::MultiplyMat(const Matrix4D *source){
    NS_STCC MultiplyMatrix(this->_m, source->_m, this->_m);
}

void NS_STCC Matrix4D::CreateTranslate(double x,double y,double z,Matrix4D* dst){
    ASSERT(dst);
    memcpy(dst, &IDENTITY, sizeof(Matrix4D));
    dst->_m[12] = x;
    dst->_m[13] = y;
    dst->_m[14] = z;
}

void NS_STCC Matrix4D::CreateRotationX(double angle, Matrix4D* dst){
    ASSERT(dst);
    memcpy(dst, &IDENTITY, sizeof(Matrix4D));
    
    double co = cos(angle);
    double si = sin(angle);
    
    dst->_m[5]  = co;
    dst->_m[6]  = si;
    dst->_m[9]  = -si;
    dst->_m[10] = co;
}
void NS_STCC Matrix4D::CreateRotationY(double angle, Matrix4D* dst){
    ASSERT(dst);
    memcpy(dst, &IDENTITY, sizeof(Matrix4D));
    
    double co = cos(angle);
    double si = sin(angle);
    
    dst->_m[0] = co;
    dst->_m[2] = -si;
    dst->_m[8] = si;
    dst->_m[10] = co;
}
void NS_STCC Matrix4D::CreateRotationZ(double angle, Matrix4D* dst){
    ASSERT(dst);
    memcpy(dst, &IDENTITY, sizeof(Matrix4D));
    
    double co = cos(angle);
    double si = sin(angle);
    
    dst->_m[0] = co;
    dst->_m[1] = si;
    dst->_m[4] = -si;
    dst->_m[5] = co;
}

void NS_STCC Matrix4D::CreatePerspective(double left,double right,double top,double bottom,double znear,double zfar,Matrix4D *dst){
    ASSERT(dst);
    memcpy(dst, &IDENTITY, sizeof(Matrix4D));
    dst->_m[0] = 2*znear/(right-left);
    dst->_m[5] = 2*znear/(top-bottom);
    dst->_m[8] = (right+left)/(right-left);
    dst->_m[9] = (top+bottom)/(top-bottom);
    dst->_m[10] = (zfar+znear)/(znear-zfar);
    dst->_m[11] = -1;
    dst->_m[14] = -2*zfar*znear/(zfar-znear);
    dst->_m[15] = 0;
}

void NS_STCC Matrix4D::CreatePerspective(double width,double height,double znear,double zfar,Matrix4D *dst){
    ASSERT(dst);
    memcpy(dst, &IDENTITY, sizeof(Matrix4D));
    dst->_m[0] = 2*znear/(width);
    dst->_m[5] = 2*znear/(height);
    dst->_m[10] = (zfar+znear)/(znear-zfar);
    dst->_m[11] = -1.0f;
    dst->_m[14] = 2*zfar*znear/(znear-zfar);
    dst->_m[15] = 0;
}

#include <stdio.h>
void NS_STCC Matrix4D::Log()
{
    printf("\n%lf,%lf,%lf,%lf\n%lf,%lf,%lf,%lf\n%lf,%lf,%lf,%lf\n%lf,%lf,%lf,%lf",
                _m[0],_m[4],_m[8],_m[12],
                _m[1],_m[5],_m[9],_m[13],
                _m[2],_m[6],_m[10],_m[14],
                _m[3],_m[7],_m[11],_m[15]);
}

void NS_STCC MultiplyMatrix(const double* m1,const double* m2,double* dst){
    double ret[16];
    
    ret[0]  = m1[0] * m2[0]  + m1[4] * m2[1] + m1[8]   * m2[2]  + m1[12] * m2[3];
    ret[1]  = m1[1] * m2[0]  + m1[5] * m2[1] + m1[9]   * m2[2]  + m1[13] * m2[3];
    ret[2]  = m1[2] * m2[0]  + m1[6] * m2[1] + m1[10]  * m2[2]  + m1[14] * m2[3];
    ret[3]  = m1[3] * m2[0]  + m1[7] * m2[1] + m1[11]  * m2[2]  + m1[15] * m2[3];
    
    ret[4]  = m1[0] * m2[4]  + m1[4] * m2[5] + m1[8]   * m2[6]  + m1[12] * m2[7];
    ret[5]  = m1[1] * m2[4]  + m1[5] * m2[5] + m1[9]   * m2[6]  + m1[13] * m2[7];
    ret[6]  = m1[2] * m2[4]  + m1[6] * m2[5] + m1[10]  * m2[6]  + m1[14] * m2[7];
    ret[7]  = m1[3] * m2[4]  + m1[7] * m2[5] + m1[11]  * m2[6]  + m1[15] * m2[7];
    
    ret[8]  = m1[0] * m2[8]  + m1[4] * m2[9] + m1[8]   * m2[10] + m1[12] * m2[11];
    ret[9]  = m1[1] * m2[8]  + m1[5] * m2[9] + m1[9]   * m2[10] + m1[13] * m2[11];
    ret[10] = m1[2] * m2[8]  + m1[6] * m2[9] + m1[10]  * m2[10] + m1[14] * m2[11];
    ret[11] = m1[3] * m2[8]  + m1[7] * m2[9] + m1[11]  * m2[10] + m1[15] * m2[11];
    
    ret[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8]  * m2[14] + m1[12] * m2[15];
    ret[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9]  * m2[14] + m1[13] * m2[15];
    ret[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];
    ret[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];
    
    memcpy(dst, ret, sizeof(Matrix4D));
}

const NS_STCC Matrix4D NS_STCC Matrix4D::IDENTITY = Matrix4D(1, 0, 0, 0,
                                                0, 1, 0, 0,
                                                0, 0, 1, 0,
                                                0, 0, 0, 1);

