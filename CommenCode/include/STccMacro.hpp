//
//  STccMacro.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccMacro_hpp
#define STccMacro_hpp

#include <stdlib.h>

#define ASSERT(cmd) do{ if(!(cmd)) abort(); } while(0)

#define SAFE_DELETE(p) do{ delete p; p = nullptr; }while(0)

#define FOREACH_ARRAY(i,l) for(i = 0 ; i < l ; ++i)

typedef unsigned char           uint8_st;
typedef unsigned short          uint16_st;
typedef unsigned long           uint32_st;
typedef unsigned long long      uint64_st;
typedef unsigned int            uint_st;

typedef char           int8_st;
typedef short          int16_st;
typedef long           int32_st;
typedef long long      int64_st;
typedef int            int_st;

//////////////////////////////////////////
//NAMESPACE
//////////////////////////////////////////
#include "STccNameSpace.hpp"

//////////////////////////////////////////
//DEBUG CONFIG
//////////////////////////////////////////
#define ST_DEBUG 1
#define ST_DEBUG_PRINT_FILENAME 1
#define ST_DEBUG_PRINT_FUNCTION 1
#define ST_DEBUG_PRINT_LINE 1

//////////////////////////////////////////
//DEPRECATED
//////////////////////////////////////////
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#define ST_DEPRECATED __attribute__((deprecated))
#else
#define ST_DEPRECATED
#endif

#endif /* STccMacro_hpp */
