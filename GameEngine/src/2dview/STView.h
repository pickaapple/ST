//
//  View.h
//  Legend of Weapons
//
//  Created by Apple on 2017/3/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef View_h
#define View_h

#include "ST2DViewMacros.h"
#include "STPrimitiveData.h"
#include "STCoordinateAxis.h"

NS_VIEW2D_BEGIN

    class _View{
    private:
        float (*vertex_array)[3] = 0;
    protected:
    public:
        NS_MATH _Matrix4f modelMat4f;
        NS_ST _BeforeViewDrawFunCallBack beforeDraw;
        _CoordinateAxis *coor_axis = 0;
        float scale_xyz[3] = {1.0,1.0,1.0};
        float (*color_array)[4] = 0;
        _PrimitiveData * primitive_data;
        _View();
        ~_View();
        _View(_PrimitiveData * primitive_data,_CoordinateAxis *coor_axis,float (*color_array)[4] = 0);
        //function
        void resetVertexArray(_CoordinateAxis *local_coor_axis);
        //virtual function
        virtual void draw();
    };

NS_VIEW2D_END
#endif /* View_h */
