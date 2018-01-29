//
//  STgeWindow.cpp
//  STGameEngine
//
//  Created by yhys on 2017/9/4.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

//STGameEngine
#include "STgeApplication.hpp"
#include "STgeWindow.hpp"
//STDeskSwitch
#include "STdsWindow.hpp"


////////////////////////////////////////
//Window adapter for STDeskSwitch
////////////////////////////////////////
inline void InitNativeWindow(NS_STGE Window* stgeWindow,uint_st width, uint_st height, uint_st orignX, uint_st orignY, const char* title)
{
#if CONFIG_STGE_USING_STDS
    stgeWindow->_nativeWindow = new NS_STDS Window(width,height,orignX,orignY,title);
#endif
    
}

inline void CreateNativeWindow(NS_STGE Window* stgeWindow)
{
#if CONFIG_STGE_USING_STDS
    ASSERT(SUCCESS == stgeWindow->_nativeWindow->Create());
    //Config STDS window
    stgeWindow->_nativeWindow->_windowConfig._acceptMouseMoveEvent = true;
    stgeWindow->_nativeWindow->_windowConfig._receiveEventOnlyInWindow = true;
#endif
}

inline void SetNativeWindowDelegate(NS_STGE Window* stgeWindow, NS_STGE WindowDelegate* delegate)
{
#if CONFIG_STGE_USING_STDS
    stgeWindow->_nativeWindow->SetDelegate(delegate);
#endif
}

inline bool IsNativeWindowRunning(NS_STGE Window* stgeWindow)
{
#if CONFIG_STGE_USING_STDS
    return stgeWindow->_nativeWindow->IsRuning();
#endif
}

inline void NativeWindowRunOnce(NS_STGE Window* stgeWindow)
{
#if CONFIG_STGE_USING_STDS
    stgeWindow->_nativeWindow->PollEvents();
#endif
}

////////////////////////////////////////
//Window
////////////////////////////////////////
void NS_STGE Window::Init(uint_st width, uint_st height, uint_st orignX, uint_st orignY, const char* title)
{
    InitNativeWindow(this, width, height, orignX, orignY, title);
    CreateNativeWindow(this);
}

void NS_STGE Window::SetDelegate(WindowDelegate *delegate)
{
    _delegate = delegate;
    SetNativeWindowDelegate(this, delegate);
}

bool NS_STGE Window::IsRunning()
{
    return IsNativeWindowRunning(this);
}

void NS_STGE Window::RunOnce()
{
    NativeWindowRunOnce(this);
}

NS_STGE Window* NS_STGE Window::Create(NS_STGE Application * app)
{
    NS_STGE Window * window = new NS_STGE Window(app);
    app->RegisterWindow(window);
    return window;
}

void NS_STGE Window::Destroy(NS_STGE Window* window)
{
    window->_app->LogoutWindow(window);
    delete window;
}

NS_STGE Window::Window(NS_STGE Application * app)
:_delegate(nullptr)
,_app(app)
{
}

NS_STGE Window::~Window()
{
    #if CONFIG_STGE_USING_STDS
    if(_nativeWindow)
        delete _nativeWindow;
    _nativeWindow = nullptr;
    #endif
}
