//
//  STdsApplication.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/28.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STdsApplication_hpp
#define STdsApplication_hpp

#include "STdsMacro.hpp"
#include "STdsPlatformFeature.hpp"
#include "STdsKeyboard.hpp"
#include "STdsMouse.hpp"

NS_STDS_BEGIN

class ApplicationDelegate;

class Application
{
public:
    bool Init();
    
    void InitKeyCode();
    
    void InitMouseCode();
    
    void SetDelegate(ApplicationDelegate *delegate);
    
    ////////////////////////////////////////
    //Contructor
    Application();
    
    ~Application();
    
    ApplicationDelegate *_delegate;
    
    Keyboard        _keyboard;
    
    Mouse           _mouse;
    
    ST_APPLICATION_PLATFORM_FEATURE;
};

class ApplicationDelegate
{
public:
    virtual bool ApplicationDidFinishLaunching()  = 0;
    
    virtual bool ApplicationDidEnterBackground()  = 0;
    
    virtual bool ApplicationDidEnterForeground()  = 0;
    
    virtual void ApplicationWillFinish()          = 0;
};

extern Application* STApp;

NS_STDS_END

#endif /* STdsApplication_hpp */
