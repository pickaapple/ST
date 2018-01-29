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

//Init value
NS_STGE Game* NS_STGE Game::_game = nullptr;

//Attribute
void NS_STGE Game::SetFrameInterval(int interval)
{
    _intervalMS = interval;
}

uint32_st NS_STGE Game::GetFrameInterval()
{
    return _intervalMS;
}

NS_STGE Application& NS_STGE Game::GetApp()
{
    return *_app;
}

//Life circle
void NS_STGE Game::Run()
{
    int32_st  sleepTime;
    uint32_st lastTime,nowTime;
    
    lastTime = nowTime = _app->GetCurrentMillSecond();
    
    while(_mainWindow->IsRunning())
    {
        _mainWindow->RunOnce();
        
        //frame time control
        nowTime = _app->GetCurrentMillSecond();
        
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
    _game = this;
    _app = &Application::Singleton();
    //Window init
    _mainWindow = NS_STGE Window::Create(_app);
    _mainWindow->Init(config._windowWidth, config._windowHeight,
                      config._windowOrignX, config._windowOrignY,
                      config._windowTitle);
}

NS_STGE Game::~Game()
{
    NS_STGE Window::Destroy(_mainWindow);
    _mainWindow = nullptr;
}
