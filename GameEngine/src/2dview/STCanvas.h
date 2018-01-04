//
//  Canvas.h
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef Canvas_h
#define Canvas_h

#include "ST2DViewMacros.h"
#include "STView.h"
#include "STLinkedList.h"
#include "STCoordinateAxis.h"

NS_VIEW2D_BEGIN

// CLASS CANVAS
class _Canvas{
private:
    NS_STR _LinkedList *views;
protected:
public:
    NS_MATH _Matrix4f projectMat4f;
    NS_MATH _Matrix4f modelMat4f;
    unsigned long canvas_id=0;
    //xyz坐标轴
    _CoordinateAxis coordinateAxis;
    
    _Canvas();
    _Canvas(const int& orign_x,const int &orign_y,const int &orign_z);
    ~_Canvas();
    //attribute set
    inline void setOrign(const int &gl_x,const int &gl_y,const int &gl_z,const bool &di_po_gl_x,const bool &di_po_gl_y,const bool &di_po_gl_z){
        coordinateAxis.orign_x = gl_x;
        coordinateAxis.orign_y = gl_y;
        coordinateAxis.orign_z = gl_z;
        coordinateAxis.di_po_gl_x = di_po_gl_x;
        coordinateAxis.di_po_gl_y = di_po_gl_y;
        coordinateAxis.di_po_gl_z = di_po_gl_z;
    };
    inline void setOrignXY(const int &gl_x,const int &gl_y){
        coordinateAxis.orign_x = gl_x;
        coordinateAxis.orign_y = gl_y;
    };
    //views set
    void addView(_View* view);
    //function fun
    void draw();
};

NS_VIEW2D_END

#endif /* Canvas_h */
