//
//  STgeApplication.hpp
//  STGameEngine
//
//  Created by Apple on 2017/4/16.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STgeApplication_hpp
#define STgeApplication_hpp


#include "structure/STccString.hpp"

#include "STgeMacro.hpp"

NS_STGE_BEGIN

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
    
    NS_STCC string GetVersion();
    
    ////////////////////////////////////////
    //Constructor
    Application();
    
    ~Application();
    
protected:
    NS_STCC string _version;
};

NS_STGE_END

#endif /* STgeApplication_hpp */
