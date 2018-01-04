//
//  STTimeController.h
//  Legend of Weapons
//
//  Created by yhys on 2017/4/22.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef STTimeController_h
#define STTimeController_h


#include "STInternal.h"
#include "STObject.h"
NS_ST_BEGIN

class _TimeEvent:public _STObject{
public:
    _TimeEvent* next = 0;
    long triggerTime = 0l;
    _TimeEventFunCallBack event;
    _TimeEvent(long triggerTime,_TimeEventFunCallBack event);
};
class _TimeLine{
    _TimeEvent first;
public:
    _TimeLine();
    void putEventOnLine(_TimeEvent *event);
    _TimeEvent* getFirst();
    _TimeEvent* popFirst();
};
class _TimeController{
protected:
    static _TimeController* shareTimeController;
public:
    _TimeController(long refreshInternal);
    _TimeLine timeline;
    long refreshInterval = 0l;
    long currentTime = 0l;
    ~_TimeController();
    void init();
    void update();
    void putEventOnLine(_TimeEvent *event);
    void setInternal(long internal);
    void release();
    static _TimeController* getInstance();
};
NS_ST_END

#endif /* STTimeController_h */
