//
//  STdsWindow.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/4/16.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef STWindow_hpp
#define STWindow_hpp

#include "STccMacro.hpp"

#include "STdsMacro.hpp"
#include "STdsPlatformFeature.hpp"
#include "STdsKeyboard.hpp"
#include "STdsMouse.hpp"

NS_STDS_BEGIN

class Application;

////////////////////////////////////////
//Window config
struct WindowConfig
{
    ////////////////////////////////////////
    //Mouse event config
    
    //if accept mouse move event always.
    bool _acceptMouseMoveEvent;
    
    //if reveive mouse move event only in window.
    bool _receiveEventOnlyInWindow;
};

////////////////////////////////////////
//Window delegate interface
class IWindowDelegate
{
public:
    virtual void WindowDidFinishLaunching()  = 0;
    
    virtual void WindowWillEnterBackground() = 0;
    
    virtual void WindowDidEnterBackground()  = 0;
    
    virtual void WindowDidEnterForeground()  = 0;
    
    virtual void WindowWillFinish()          = 0;
};

////////////////////////////////////////
//Window
class Window
{
    ////////////////////////////////////////
    //Window life circle notification
public:
    virtual bool ShouldClose();
    
    bool IsRuning();
    
    void SetDidClose();
    
protected:
    bool _runing;
    
    ////////////////////////////////////////
    //Window Control
public:
    int8_st Create();
    
    void    Show();
    
    void    Focus();
    
    void    Hiden();
    
    void    PollEvents();
    
    void SetDelegate(IWindowDelegate *delegate){ _delegate = delegate; };
    
    IWindowDelegate* GetDelegate(){ return _delegate; };

    ST_WINDOW_PLATFORM_FEATURE;

    Application*    _applicatin;
    
protected:
    IWindowDelegate* _delegate;
    
    ////////////////////////////////////////
    //Window Attribute
public:
    void ResetWindowSize(uint16_st width,uint16_st height);

    void ResetWindowPosi(uint16_st x,uint16_st y);

public:
    uint16_st   _width;
    uint16_st   _height;
    uint16_st   _orignX;
    uint16_st   _orignY;
    
    const char* _title;
    
    WindowConfig _windowConfig;
    
    ////////////////////////////////////////
    //Window Event
public:
    OnKeyboardEvent  _hKeyBordEvent;
    OnMouseEvent     _hMouseBordEvent;
    
    ////////////////////////////////////////
    //Window Contructor
public:
    Window(uint16_st width,uint16_st height,uint16_st orign_x,uint16_st orign_y,const char*title);

    Window();
    
    ~Window();
};


NS_STDS_END

#endif /* STWindow_hpp */
