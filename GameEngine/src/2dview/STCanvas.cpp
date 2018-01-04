//
//  Canvas.cpp
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STCanvas.h"

NS_VIEW2D_BEGIN

// CLASS CANVAS
_Canvas::_Canvas():projectMat4f(),modelMat4f(){
    views = ST_NEW_INFO("NEW views(LinkedList) IN Canvas::Canvas() INNER STgame") NS_STR _LinkedList();
    NS_ST one_time = true;
};
_Canvas::_Canvas(const int& orign_x,const int &orign_y,const int &orign_z):_Canvas(){
    coordinateAxis.orign_x = orign_x;
    coordinateAxis.orign_y = orign_y;
    coordinateAxis.orign_z = orign_z;
};
_Canvas::~_Canvas(){
    NS_STR _NodeBase* cur = views->first;
    while(cur!=0){
        ST_DELETE_DES_INFO(_View,(_View *)cur->payload,"DELETE (View) IN Canvas::~Canvas() INNER STgame");
        cur = cur->next;
    }
    ST_DELETE_DES_INFO(_LinkedList,views,"DELETE views(LinkedList) IN Canvas::~Canvas() INNER STgame");
};

void _Canvas::addView(_View *view){
    views->push_back(ST_NEW_INFO("NEW (NodeBase) TO line the view IN void Canvas::addView(View) INNER STgame") NS_STR _NodeBase(view));
};
void _Canvas::draw(){
    NS_STR _NodeBase *cur= views->first;
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projectMat4f.m);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(modelMat4f.m);
    //    if(NS_ST one_time){
    //        NS_MATH _Matrix4f m;
    //        glGetFloatv(GL_PROJECTION_MATRIX, m.m);
    //        m.log();
    //        glGetFloatv(GL_MODELVIEW_MATRIX, m.m);
    //        m.log();
    //        NS_ST one_time = false;
    //    }
    while(cur!=0){
        ((_View *)(cur->payload))->draw();
        cur = cur->next;
    }
};

NS_VIEW2D_END

////////////////////
//PUBLIC API
////////////////////

#include "STWindow.h"

NS_ST_BEGIN

Canvas createACanvas(const int& orign_x, const int& orign_y, const int& orign_z){
    return ST_NEW_INFO("NEW (Canvas) IN Canvas ::createACanvas(const int&, const int&, const int&) PUBLIC API") NS_VIEW2D _Canvas(orign_x, orign_y, orign_z);
};
Canvas setCanvasProjection(Canvas canvas,float width,float height,float znear,float zfar){
    NS_MATH _Matrix4f::createPerspective(width, height, znear, zfar, &((NS_VIEW2D _Canvas*)canvas)->projectMat4f);
    return canvas;
};
Canvas setCanvasProjection(Canvas canvas,float left,float right,float top,float bottom,float znear,float zfar){
    NS_MATH _Matrix4f::createPerspective(left, right, top, bottom, znear, zfar, &((NS_VIEW2D _Canvas*)canvas)->projectMat4f);
    return canvas;
};
void addCanvasToWindow(Window window,Canvas canvas){
    ((_Window*)window)->container->addCanvas((NS_VIEW2D _Canvas *)canvas);
};

NS_ST_END
