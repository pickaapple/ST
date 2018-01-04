//
//  STdsPlatformFeature.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/31.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STdsPlatformFeature_hpp
#define STdsPlatformFeature_hpp

////////////////////////////////////

#include "STdsPlatformCheck.hpp"

#if ST_TARGET_OS == ST_OS_MAC
#include "mac/STdsPlatformOfMac.h"
#else
#error "No supported window creation API selected"
#endif


#endif /* STPlatform_hpp */
