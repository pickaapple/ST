//
//  main.cpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <OpenGL/gl.h>

#include "STdsWindow.hpp"


void OnKeyboardEvent(uint16_st key, uint16_st modifierFlag, int8_st state)
{
    std::cout<<"key:"<<key<<" modifier:"<< modifierFlag <<" state:"<<(int)state<<std::endl;
}

void OnMouseEvent(NS_STCC Point2D point, int8_st buttonType, int8_st state, uint16_st modifierFlag)
{
    switch (state) {
        case NS_STDS STMousePressDown:
            switch (buttonType) {
                case ST_MOUSE_BUTTON_LEFT:
                    std::cout<<"left button is click , and the point x:"<<point._x<<" y:"<<point._y<<" modifierFlag:"<<modifierFlag<<std::endl;
                    break;
                case ST_MOUSE_BUTTON_RIGHT:
                    std::cout<<"right button is click , and the point x:"<<point._x<<" y:"<<point._y<<" modifierFlag:"<<modifierFlag<<std::endl;
                    break;
            }
            break;
        case NS_STDS STMousePressMove:
            std::cout<<"mouse is moving to point x:"<<point._x<<" y:"<<point._y<<" modifierFlag:"<<modifierFlag<<std::endl;
            break;
        default:
            break;
    }
}

void display()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.85f, 0.35f);
    glBegin(GL_QUADS);
    {
        glVertex3f(  -1,  -1, 0.0);
        glVertex3f(  1,  -1, 0.0);
        glVertex3f(  1,  1, 0.0);
        glVertex3f(  -1,  1, 0.0);
    }
    glEnd();
    glFlush();
}

int main(int argc, const char * argv[]) {
    std::cout<<"hello world"<<std::endl;
    NS_STDS Window window(100,100,0,0,"hello ds");

    //window config
    window._windowConfig._acceptMouseMoveEvent = false;
    window._windowConfig._receiveEventOnlyInWindow = true;
    
    //input event
    //window._hKeyBordEvent   = OnKeyboardEvent;
    //window._hMouseBordEvent = OnMouseEvent;
    
    if(1 != window.Create())
    {
        return 3;
    }
    
    while(window.IsRuning())
    {
        display();
        window.PollEvents();
        usleep(500);
    }
    return 1;
}
