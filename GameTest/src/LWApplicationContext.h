//
//  LWApplicationContext.h
//  Legend of Weapons
//
//  Created by yhys on 2017/4/29.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef LWApplicationContext_h
#define LWApplicationContext_h

#include "LWMarco.h"

typedef void (*ApplicationWillFinishCallBack)();

class LWApplicationContext : public NS_ST STApplicationContext{
public:
    ApplicationWillFinishCallBack willFinish;
    
    LWApplicationContext();
    
    void setApplicationWillFinishCallBack(ApplicationWillFinishCallBack willF);
    virtual bool ApplicationDidFinishLaunching() override;
    virtual bool ApplicationDidEnterBackground() override;
    virtual bool ApplicationWillEnterForeground() override;
    virtual void ApplicationWillFinish() override;
};

#endif /* LWApplicationContext_h */
