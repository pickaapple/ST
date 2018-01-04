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

#define PI 3.1415926535898f


NS_STGE_BEGIN

class Application;
class Window;

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
    
    Application& GetAppInfo();
    
    ////////////////////
    //World time
    ////////////////////
    uint32_st GetCurrentMillSecond();
    
    uint32_st GetApplicationMillSecond();
    
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
    uint32_st         _appStartTime;
    
    Application *     _appInfo;
    Window *          _mainWindow;
    
    static Game*      _game;
};

NS_STGE_END

#endif /* STgame_h */
