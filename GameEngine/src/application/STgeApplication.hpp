//
//  STgeApplication.hpp
//  STGameEngine
//
//  Created by Apple on 2017/4/16.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STgeApplication_hpp
#define STgeApplication_hpp

#include "structure/STccListArray.hpp"
#include "structure/STccString.hpp"

#include "STgeMacro.hpp"
#include "STdsTime.hpp"

NS_STGE_BEGIN

class Window;

class Application
{
public:
    enum Platform
    {
        OS_UNKNOW,
        
        OS_MAC,
        
        OS_WINDOWS,
        
        OS_IPHONE,
        
        OS_ANDROID
    };
    ////////////////////////////////////////
    //Attribute
    Platform GetTargetPlatform();
    
    uint32_st GetApplicationAliveMillSecond();
    
    uint32_st GetCurrentMillSecond();
    
    NS_STCC string GetVersion();
    ////////////////////////////////////////
    //Window Records : Only record window's activity info
    void RegisterWindow(Window *window);
    
    void LogoutWindow(Window *window);
    
    ////////////////////////////////////////
    //Constructor
    static Application& Singleton();
    
    Application();
    
    ~Application();
    
protected:
    static Application * _app;
    
    NS_STCC ListArray<Window*> _windows;
    
    NS_STCC string _version;
    //Time
    NS_STDS Time   _time;
    
    uint32_st         _appStartTime;
};

NS_STGE_END

#endif /* STgeApplication_hpp */
