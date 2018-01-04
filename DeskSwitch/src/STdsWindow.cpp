//
//  STdsWindow.cpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/31.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STdsWindow.hpp"

bool NS_STDS Window::ShouldClose()
{
    return true;
}

bool NS_STDS Window::IsRuning()
{
    return _runing;
}

void NS_STDS Window::SetDidClose()
{
    _runing = false;
}

void NS_STDS Window::ResetWindowSize(uint16_st width, uint16_st height)
{
    _width = width;
    _height = height;
}

NS_STDS Window::Window(uint16_st width,uint16_st height,uint16_st orignX,uint16_st orignY,const char*title)
:_width(width)
,_height(height)
,_orignX(orignX)
,_orignY(orignY)
,_title(title)
,_runing(true)
{
}

NS_STDS Window::Window()
:_runing(true)
{
}

NS_STDS Window::~Window()
{
}
