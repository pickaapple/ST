//
//  main.cpp
//  Legend of Weapons
//
//  Created by Apple on 2017/4/4.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//
#include <OpenGL/gltypes.h>
#include <iostream>

#include "LWApplicationContext.h"

USING_NS_ST

Canvas canvas;
View v;
PrimitiveData data;
Matrix4f roato;
int loop;
void timeE(){
    ++loop;
    translateView(v, loop*0.005, loop*-0.005, 0);
};
PrimitiveData createSword(){
    GLint *first = new GLint[3]{0,4,8};
    GLsizei *count = new GLsizei[3]{4,4,5};
    float (*vert)[3] = new float[13][3]{2.2,0,0 ,3.8,0,0, 3.8,3.4,0 ,2.2,3.4,0,
                            0,3.4,0 ,6,3.4,0 ,6,4.5,0 ,0,4.5,0 ,
                            2.1f,4.5,0 ,3.9f,4.5,0 ,3.9f,10,0 ,3.0f,12,0 ,2.1f,10,0};
    float (*color)[4] = new float[13][4]{0.83,0.60,0.43,1.0, 0.83,0.60,0.43,1.0, 0.83,0.60,0.43,1.0 ,0.83,0.60,0.43,1.0 ,
                            0.83,0.60,0.43,1.0, 0.83,0.60,0.43,1.0, 0.83,0.60,0.43,1.0 ,0.83,0.60,0.43,1.0 ,
                            0.80,0.80,0.80,1.0 ,0.86,0.86,0.86,1.0 ,0.89,0.89,0.89,1.0 ,0.86,0.86,0.86,1.0 ,0.80,0.80,0.80,1.0};
    return createAPrimitiveData(0x0001,13,first,count,3,GL_POLYGON_ST,vert,color);
};
void beforeViewDraw(View view){
    multiplyViewModleMat(view, roato);
};
void appFinishCallBack(){
    deleteMatrix4f(roato);
    deletePrimitiveData(data);
};
int main(int argc, char * argv[]){
    LWApplicationContext context;
    context.setApplicationWillFinishCallBack(appFinishCallBack);
    initApplication(context);
    canvas = setCanvasProjection(createACanvas(0, 0, -1), 50, 50, 1, 100);
    data = createSword();
    v = setBeforeViewDrawFunCallBack(createAView(canvas,data),beforeViewDraw);
    addCanvasToWindow(getDefaultMainWindow(), canvas);
    roato = createRotationZ(-PI/30*getWindowsRefreshInternal()/1000.0f);
    return runApplication();
}
