
//  STView.cpp
//  Legend of Weapons
//
//  Created by Apple on 2017/3/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STView.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

NS_VIEW2D_BEGIN

// CLASS VIEW
_View::_View(){
};
_View::_View(_PrimitiveData * primitive_data,_CoordinateAxis *coor_axis,float (*color_array)[4]){
    this->primitive_data = primitive_data;
    this->coor_axis = coor_axis;
    vertex_array = ST_NEW_INFO("NEW[] vertex_array((*float)[3]) IN View::View() INNER STgame") float [primitive_data->vertex_count][3];
    resetVertexArray(coor_axis);
    this->color_array = color_array;
};

_View::~_View(){
    ST_DELETE_ARRAY_NOT_DES_INFO(vertex_array,"DELETE[] vertex_array((*float)[3]) IN View::~View() INNER STgame");
    ST_DELETE_ARRAY_NOT_DES_INFO(color_array,"DELETE[] color_array((*float)[4]) IN View::~View() INNER STgame");
};
void _View::resetVertexArray(_CoordinateAxis *coor_axis){
    coor_axis->makeOutCoors(vertex_array,primitive_data, 3);
};

void _View::draw(){
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertex_array);
    if(color_array==0){
        glColorPointer(4, GL_FLOAT, 0, primitive_data->prim_co_array);
    }else{
        glColorPointer(4, GL_FLOAT, 0, color_array);
    }
//    glPushMatrix();
    if(beforeDraw)
        beforeDraw((View)this);
    glMultMatrixf(modelMat4f.m);
    glMultiDrawArrays(primitive_data->mode, primitive_data->first, primitive_data->count, primitive_data->primcount);
//    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
};

NS_VIEW2D_END

/////////////////////////
//PUBLIC API
/////////////////////////

#include "STCanvas.h"

NS_ST_BEGIN

View createAView(Canvas canvas,PrimitiveData primitive_data,float (*color_array)[4]){
    NS_VIEW2D _View *ret = ST_NEW_INFO("NEW (View) IN View createAView(Canvas,PrimitiveData,(*float)[4]) PUBLIC API") NS_VIEW2D _View((NS_VIEW2D _PrimitiveData*)primitive_data,&(((NS_VIEW2D _Canvas*)canvas)->coordinateAxis),color_array);
    ((NS_VIEW2D _Canvas*)canvas)->addView(ret);
    return ret;
};
View setBeforeViewDrawFunCallBack(View view,_BeforeViewDrawFunCallBack callback){
    ((NS_VIEW2D _View *)view) -> beforeDraw = callback;
    return view;
};

View multiplyViewModleMat(View view, Matrix4f mat){
    ST_ASSERT(mat);
    ((NS_VIEW2D _View *)view) -> modelMat4f.multiplyMat((NS_MATH _Matrix4f*)mat);
    return view;
};
void translateView(View view,float x,float y,float z){
    ((NS_VIEW2D _View*)view)->modelMat4f.translate(x, y, z);
};


NS_ST_END

