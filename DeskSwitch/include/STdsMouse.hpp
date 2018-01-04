//
//  STdsMouse.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STMouse_hpp
#define STMouse_hpp

//STCommenCode
#include "STccMacro.hpp"
#include "graphic/STccGeometry.hpp"

//STDeskSwitch
#include "STdsMacro.hpp"


#define ST_MOUSE_BUTTON_UNKNOW  0
#define ST_MOUSE_BUTTON_LEFT    1
#define ST_MOUSE_BUTTON_RIGHT   2
#define ST_MOUSE_BUTTON_MID     3
#define ST_MOUSE_BUTTON_3       4
#define ST_MOUSE_BUTTON_4       5
#define ST_MOUSE_BUTTON_5       6
#define ST_MOUSE_BUTTON_6       7
#define ST_MOUSE_BUTTON_7       8
#define ST_MOUSE_BUTTON_8       9

#pragma GCC visibility push(default)

NS_STDS_BEGIN
////////////////////////////////////////

enum STMousePressState
{
    STMousePressDown,
    STMousePressDrag,
    STMousePressUp,
    STMousePressMove
};

typedef void (*OnMouseEvent)(NS_STCC Point2D point, int8_st buttonType, int8_st state, uint16_st modifierFlag);

////////////////////////////////////////

class Mouse
{
public:
    void      SetPlatformMouse(uint16_st uIndex,uint16_st platformMouse);
    
    uint16_st GetPlatformMouse(uint16_st uIndex);
    
public:
    Mouse();
    
    virtual ~Mouse();

protected:
    uint16_st _platformMouses[16];
};

NS_STDS_END

#pragma GCC visibility pop

#endif /* STMouse_hpp */
