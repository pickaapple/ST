//
//  STdsKeyboard.cpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/30.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STdsKeyboard.hpp"

////////////////////////////////////////
//Keyboard

void NS_STDS Keyboard::SetPlatformKey(uint16_st uIndex, uint16_st platformKey)
{
    _platformKeys[uIndex] = platformKey;
}

uint16_st NS_STDS Keyboard::GetPlatformKey(uint16_st uIndex)
{
    return _platformKeys[uIndex];
}

NS_STDS Keyboard::Keyboard()
{
}

NS_STDS Keyboard::~Keyboard()
{
}
