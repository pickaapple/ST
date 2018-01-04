//
//  STPrimitiveData.hpp
//  Legend of Weapons
//
//  Created by Apple on 2017/4/7.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef StaticPrimitiveData_hpp
#define StaticPrimitiveData_hpp

#include "ST2DViewMacros.h"
#include <OpenGL/gl.h>

NS_VIEW2D_BEGIN

    class _PrimitiveData{
    public:
        unsigned long prim_id;
        int vertex_count = 0;
        int *prim_coor_lrbtfb;
        GLint *first = 0;
        GLsizei *count = 0;
        GLsizei primcount = 0;
        GLenum mode = GL_TRIANGLE_STRIP;
        float (*prim_ve_array)[3] = 0;
        float (*prim_co_array)[4] = 0;
        _PrimitiveData(const unsigned long &prim_id,const int &vertex_count,GLint *first,GLsizei *count,const GLsizei &primcount,const GLenum &mode,float (*prim_ve_array)[3],float (*prim_co_array)[4]);
        ~_PrimitiveData();
    };

NS_VIEW2D_END

#endif /* STPrimitiveData_h */
