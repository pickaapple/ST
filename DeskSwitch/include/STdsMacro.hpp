//
//  STdsMacro.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/4/15.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STdsMacro_hpp
#define STdsMacro_hpp

//////////////////////////////////////////
//NAMESPACE
//////////////////////////////////////////
#ifdef __cplusplus
//STDeskSwitch
#define STDS              STds
#define NS_STDS_BEGIN     namespace STDS {
#define NS_STDS_END       }
#define USING_NS_STDS     using namespace STDS;
#define NS_STDS           STDS::

#else
//STDeskSwitch
#define STDS
#define NS_STDS_BEGIN
#define NS_STDS_END
#define USING_NS_STDS
#define NS_STDS
#endif

#define SUCCESS 1

#endif /* STccMacro_hpp */
