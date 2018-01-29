//
//  STgeApplication.cpp
//  STGameEngine
//
//  Created by yhys on 2017/4/29.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STdsPlatformCheck.hpp"

#include "STgeApplication.hpp"

//Init Value
NS_STGE Application* NS_STGE Application::_app = nullptr;

//Attribute
inline NS_STGE Application::Platform NS_STGE Application::GetTargetPlatform()
{
#if ST_TARGET_OS == ST_OS_MAC
    return OS_MAC;
#elif T_TARGET_OS == ST_OS_WINDOWS
    return OS_WINDOWS;
#elif T_TARGET_OS == ST_OS_IOS
    return OS_IPHONE;
#elif T_TARGET_OS == ST_OS_ANDROID
    return OS_ANDROID;
#else T_TARGET_OS == ST_OS_UNKNOWN
    return OS_UNKNOW;
#endif
}

uint32_st NS_STGE Application::GetApplicationAliveMillSecond()
{
    return GetCurrentMillSecond() - _appStartTime;
}

uint32_st NS_STGE Application::GetCurrentMillSecond()
{
    return _time.GetCurrentMillSecond();
}

NS_STCC string NS_STGE Application::GetVersion()
{
    return _version;
}

//Window Records : Only record window's activity info
void NS_STGE Application::RegisterWindow(NS_STGE Window *window)
{
    _windows.AddAtLast(window);
}

void NS_STGE Application::LogoutWindow(NS_STGE Window *window)
{
    int i;
    FOREACH_ARRAY(i, _windows.Length()){
        if(_windows[i] == window){
            _windows.Remove(i);
            break;
        }
    }
}

//Constructor
NS_STGE Application& NS_STGE Application::Singleton()
{
    ASSERT(_app);
    return *_app;
}

NS_STGE Application::Application()
:_version("0.0.1")
{
    ASSERT(!_app);
    _appStartTime = GetCurrentMillSecond();
    _app = this;
}

NS_STGE Application::~Application()
{
}
