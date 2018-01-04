//
//  STdsPlatformOfMac.h
//  STDeskSwitch
//
//  Created by yhys on 2017/8/10.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STdsPlatformOfMac_h
#define STdsPlatformOfMac_h

#if defined(__OBJC__)

#else
typedef void* id;
#endif

typedef struct STWindowOfMac
{
    id _window;
}STWindowOfMac;

typedef struct STApplicationOfMac
{
    id _application;
}STApplicationOfMac;

#define ST_WINDOW_PLATFORM_FEATURE      STWindowOfMac      wom
#define ST_APPLICATION_PLATFORM_FEATURE STApplicationOfMac aom

#endif /* STdsPlatformOfMac_h */
