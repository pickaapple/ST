//
//  STgeWindow.hpp
//  STGameEngine
//
//  Created by yhys on 2017/9/4.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STgeWindow_hpp
#define STgeWindow_hpp

//STCommenCode
#include "STccMacro.hpp"

//STGameEngine
#include "STgeMacro.hpp"

#if CONFIG_STGE_USING_STDS

#include "STdsWindow.hpp"
#define NATIVE_WINDOW public: \
STds::Window* _nativeWindow;

#else

#error dont adapter other window 

#endif

NS_STGE_BEGIN

class WindowDelegate
#if CONFIG_STGE_USING_STDS
:public NS_STDS IWindowDelegate
#endif
{
};

class Window
{
public:
    ////////////////////
    //Attribute
    ////////////////////
    void Init(uint_st width, uint_st height, uint_st orignX, uint_st orignY, const char* title);
    
    void SetDelegate(WindowDelegate* delegate);
    
    ////////////////////
    //Life circle
    ////////////////////
public:
    bool IsRunning();
    
    void RunOnce();
    
    ////////////////////
    //Constructor
    ////////////////////
public:
    Window();
    
    virtual ~Window();
    
protected:
    WindowDelegate* _delegate;
    NATIVE_WINDOW;
};

NS_STGE_END

#endif /* STgeWindow_hpp */
