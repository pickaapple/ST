//
//  STgeMacro.hpp
//  STGameEngine
//
//  Created by yhys on 2017/8/28.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STgeMacro_hpp
#define STgeMacro_hpp

//////////////////////////////////////////
//NAMESPACE
//////////////////////////////////////////
#ifdef __cplusplus
//STge
#define STGE                STge
#define NS_STGE_BEGIN       namespace STGE {
#define NS_STGE_END         }
#define USING_NS_STGE       using namespace STGE;
#define NS_STGE             STGE::

#else
//STge
#define STGE                
#define NS_STGE_BEGIN       
#define NS_STGE_END         
#define USING_NS_STGE       
#define NS_STGE
#endif

#define CONFIG_STGE_USING_STDS 0
#define CONFIG_STGE_USING_GLFW 1

#endif /* STgeMacro_hpp */
