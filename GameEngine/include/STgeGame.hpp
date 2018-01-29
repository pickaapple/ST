//
//  STge.hpp
//  STGameEngine
//
//  Created by yhys on 2017/4/15.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STge_hpp
#define STge_hpp

//STCommenCode
#include "STccMacro.hpp"

//STGameEngine
#include "STgeMacro.hpp"
#include "STgeApplication.hpp"
#include "STgeWindow.hpp"

#define PI 3.1415926535898f


NS_STGE_BEGIN

class Game
{
public:
    struct Config
    {
        int_st _windowWidth;
        int_st _windowHeight;
        int_st _windowOrignX;
        int_st _windowOrignY;
        const char* _windowTitle;
    };
public:
    ////////////////////
    //Attribute
    ////////////////////
    void SetFrameInterval(int interval);
    
    uint32_st GetFrameInterval();
    
    Application& GetApp();
    
    ////////////////////
    //Life circle
    ////////////////////
    void Run();
    
    ////////////////////////////////////////
    //Constructor
    
    static Game& Singleton();
    
    Game(const Config& config = {400, 400, 100, 100, "Hello ST!"});
    
    ~Game();
protected:
    uint32_st         _intervalMS;
    uint32_st         _lastTerminal;
    
    Window *          _mainWindow;
    Application *     _app;
    static Game*      _game;
};

NS_STGE_END

#endif /* STgame_h */
