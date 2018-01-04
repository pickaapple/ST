//
//  STTimeController.c
//  Legend of Weapons
//
//  Created by yhys on 2017/4/22.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STTimeController.h"
#include "STApplicationDelegate.h"
NS_ST_BEGIN

_TimeEvent::_TimeEvent(long triggerTime,_TimeEventFunCallBack event):triggerTime(triggerTime),event(event){};

_TimeLine::_TimeLine():first(-1,nullptr){
};
void _TimeLine::putEventOnLine(_TimeEvent *event){
    _TimeEvent* cur = &first;
    while(cur->next){
        if(event->triggerTime<=cur->triggerTime)
            break;
        cur = cur->next;
    }
    event->next = cur->next;
    cur->next = event;
};
_TimeEvent* _TimeLine::getFirst(){
    return first.next;
};
_TimeEvent* _TimeLine::popFirst(){
    ST_ASSERT_LOG(first.next, "timeline is empty");
    _TimeEvent* ret = first.next;
    first.next = first.next->next;
    return ret;
};

_TimeController* _TimeController::shareTimeController = nullptr;

//call release to delete the instance of TimeController
_TimeController::~_TimeController(){
    
};
_TimeController::_TimeController(long refreshInternal){
    setInternal(refreshInternal);
    shareTimeController = this;
};
void _TimeController::init(){
    currentTime = _Application::getInstance()->getApplicationMillSecond();
};
void _TimeController::putEventOnLine(_TimeEvent *event){
    timeline.putEventOnLine(event);
};
void _TimeController::update(){
    currentTime = _Application::getInstance()->getApplicationMillSecond();
    _TimeEvent* loop_event = timeline.getFirst();
    while(loop_event && (loop_event->triggerTime <= currentTime)){
        timeline.popFirst();
        loop_event -> event();
        _TimeEvent* d = loop_event;
        loop_event = loop_event->next;
        d->release();
    };
};
void _TimeController::setInternal(long internal){
    ST_ASSERT_LOG(internal > 0,"timeController's internal should be greater than zero");
    refreshInterval = internal;
};
void _TimeController::release(){
    ST_DELETE_DES_INFO(_TimeController,shareTimeController,"DELETE shareTimeController(TimeController) IN void TimeController::release() INNER STgame");
};
_TimeController* _TimeController::getInstance(){
    ST_ASSERT_LOG(shareTimeController, "timeController should be allocated at least once");
    return shareTimeController;
};
////////////////////
//PUBLIC API
////////////////////

void putTimeEventOnLine(long futureTime,_TimeEventFunCallBack e){
    ST_ASSERT_LOG(futureTime,"futureTime should greater than zero");
    long currentTime = _Application::getInstance()->getApplicationMillSecond();
    _TimeEvent* event = ST_NEW_INFO("NEW (TimeEvent) IN void ::putTimeEventOnLine(long,TimeEventFunCallBack) INNER STgame") _TimeEvent(currentTime+futureTime,e);
    _TimeController::getInstance()->putEventOnLine(event);
};

NS_ST_END
