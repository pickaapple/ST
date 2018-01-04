//
//  STdsTime.mm
//  STDeskSwitch
//
//  Created by yhys on 2017/8/28.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#import <sys/time.h>

#import "STdsTime.hpp"


uint32_st  NS_STDS Time::GetCurrentMillSecond()
{
    long lastTime = 0;
    struct timeval currentTime;
    gettimeofday(&currentTime,NULL);
    lastTime = currentTime.tv_sec * 1000 + currentTime.tv_usec * 0.001;
    return lastTime;
}
