//
//  STdsMouse.cpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/30.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STdsMouse.hpp"

void NS_STDS Mouse::SetPlatformMouse(uint16_st uIndex,uint16_st platformMouse)
{
    _platformMouses[uIndex] = platformMouse;
}

uint16_st NS_STDS Mouse::GetPlatformMouse(uint16_st uIndex)
{
    return _platformMouses[uIndex];
}

NS_STDS Mouse::Mouse()
{
}

NS_STDS Mouse::~Mouse()
{
}
