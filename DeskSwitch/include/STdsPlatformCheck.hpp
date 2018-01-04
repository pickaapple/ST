//
//  STdsPlatformCheck.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/9/1.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STdsPlatformCheck_hpp
#define STdsPlatformCheck_hpp

#define ST_OS_UNKNOWN            0
#define ST_OS_MAC                1
#define ST_OS_WINDOWS            2
#define ST_OS_IOS                3
#define ST_OS_ANDROID            4

#define ST_TARGET_OS ST_OS_UNKNOWN
////////////////////////////////////////
//Platform recognize
////////////////////////////////////////

#if defined(__APPLE__) && !defined(ANDROID)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE    //IOS

#undef  ST_TARGET_OS
#define ST_TARGET_OS         ST_OS_IOS

#elif TARGET_OS_MAC     //MAC OS

#undef  ST_TARGET_OS
#define ST_TARGET_OS         ST_OS_MAC

#endif
#endif                  //Mac and IOS

#endif /* STdsPlatformCheck_hpp */
