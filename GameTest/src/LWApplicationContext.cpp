//
//  LWApplicationContext.cpp
//  Legend of Weapons
//
//  Created by yhys on 2017/4/29.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "LWApplicationContext.h"
#include <iostream>
LWApplicationContext::LWApplicationContext():willFinish(0){
    
};
void LWApplicationContext::setApplicationWillFinishCallBack(ApplicationWillFinishCallBack willF){
    willFinish = willF;
};
bool LWApplicationContext::ApplicationDidFinishLaunching(){
    return true;
};
bool LWApplicationContext::ApplicationDidEnterBackground(){
    return true;
};
bool LWApplicationContext::ApplicationWillEnterForeground(){
    return true;
};
void LWApplicationContext::ApplicationWillFinish(){
    LW_ASSERT(willFinish);
    willFinish();
};
