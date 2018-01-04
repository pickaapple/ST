//
//  STgeGame.cpp
//  STGameEngine
//
//  Created by yhys on 2017/8/30.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <unistd.h>

//STDeskSwitch
#include "STdsWindow.hpp"
#include "STdsTime.hpp"
//STGameEngine
#include "STgeGame.hpp"
#include "STgeWindow.hpp"
#include "STgeApplication.hpp"


//Main Window
static NS_STGE Window     s_mainWindow;

//Application
static NS_STGE Application s_app;
//Time
static NS_STDS Time   s_worldTime;


//Attribute
void NS_STGE Game::SetFrameInterval(int interval)
{
    _intervalMS = interval;
}

uint32_st NS_STGE Game::GetFrameInterval()
{
    return _intervalMS;
}

NS_STGE Application& NS_STGE Game::GetAppInfo()
{
    return s_app;
}

//World time
uint32_st NS_STGE Game::GetCurrentMillSecond()
{
    return s_worldTime.GetCurrentMillSecond();
}

uint32_st NS_STGE Game::GetApplicationMillSecond()
{
    return GetCurrentMillSecond() - _appStartTime;
}

//Life circle
void NS_STGE Game::Run()
{
    int32_st  sleepTime;
    uint32_st lastTime,nowTime;
    
    _appStartTime = lastTime = nowTime = s_worldTime.GetCurrentMillSecond();
    
    while(s_mainWindow.IsRunning())
    {
        s_mainWindow.RunOnce();
        
        //frame time control
        nowTime = s_worldTime.GetCurrentMillSecond();
        
        _lastTerminal = nowTime - lastTime;
        sleepTime = _lastTerminal - _intervalMS;
        if(sleepTime >= 0)
        {
            usleep((useconds_t)sleepTime);
        }
        lastTime = nowTime;
    }
}

//Constructor
NS_STGE Game& NS_STGE Game::Singleton()
{
    ASSERT(_game);
    return *_game;
}

NS_STGE Game::Game(const Config& config)
    :_intervalMS(300)
{
    ASSERT(!_game);
    //Window init
    s_mainWindow.Init(config._windowWidth, config._windowHeight,
                      config._windowOrignX, config._windowOrignY,
                      config._windowTitle);
    _game = this;
}

NS_STGE Game::~Game()
{
}
