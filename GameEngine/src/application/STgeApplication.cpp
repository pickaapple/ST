//
//  STgeApplication.cpp
//  STGameEngine
//
//  Created by yhys on 2017/4/29.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STdsPlatformCheck.hpp"

#include "STgeApplication.hpp"

//Attribute
NS_STGE Application::Platform NS_STGE Application::GetTargetPlatform()
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

NS_STCC string NS_STGE Application::GetVersion()
{
    return _version;
}

//Constructor
NS_STGE Application::Application()
:_version("0.0.1")
{
}

NS_STGE Application::~Application()
{
}
