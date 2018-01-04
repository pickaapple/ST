//
//  CanvasContainer.cpp
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STCanvasContainer.h"

NS_VIEW2D_BEGIN

// CLASS CONTAINER
_CanvasContainer::_CanvasContainer():base_z(-10){
    canvass = ST_NEW_INFO("NEW canvass(LinkedList) IN CanvasContainer::CanvasContainer() INNER STgame") NS_STR _LinkedList();
};
_CanvasContainer::~_CanvasContainer(){
    NS_STR _NodeBase * cur = canvass->first;
    while(cur!=0){
        ST_DELETE_DES_INFO(_Canvas,(_Canvas*)cur->payload,"DELETE canvas(Canvas) IN CanvasContainer::~CanvasContainer() INNER STgame");
        cur = cur->next;
    }
    ST_DELETE_DES_INFO(_LinkedList,canvass,"DELETE canvass(LinkedList) IN CanvasContainer::~CanvasContainer() INNER STgame");
};

void _CanvasContainer::drawAllCanvas(){
    glClearColor(base_color.red, base_color.green, base_color.blue, base_color.alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    NS_STR _NodeBase *cur = canvass->first;
    while(cur!=0){
        ((_Canvas *)cur->payload)->draw();
        cur = cur->next;
    }
};
void _CanvasContainer::addCanvas(_Canvas *canvas){
    NS_STR _NodeBase * node = ST_NEW_INFO("NEW (NodeBase) TO line the canvas IN void CanvasContainer::addCanvas(Canvas *canvas) INNER STgame") NS_STR _NodeBase(canvas);
    canvass->push_back(node);
};


NS_VIEW2D_END
