//
//  STccLog.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccLog_hpp
#define STccLog_hpp

#include "STccMacro.hpp"
#include "structure/STccString.hpp"

#pragma GCC visibility push(default)

//////////////////////////////////////////
//DEBUG SWITCH
//////////////////////////////////////////
#ifndef ST_DEBUG
#define ST_DEBUG 0
#endif

#if ST_DEBUG == 0 //Debug off
#define ST_LOG(format,...)                   do {} while(0)
#define ST_LOG_INFO(format,...)              do {} while(0)
#define ST_LOG_WARN(format,...)              do {} while(0)
#define ST_LOG_ERROR(format,...)             do {} while(0)
#elif ST_DEBUG == 1//Debug on
#define ST_LOG(format,...)            NS_STCC StLog(__FILE__,__FUNCTION__,__LINE__,NS_STCC LOG_LEVEL_TEXT,format, ##__VA_ARGS__)
#define ST_LOG_INFO(format,...)       NS_STCC StLog(__FILE__,__FUNCTION__,__LINE__,NS_STCC LOG_LEVEL_INFO,format, ##__VA_ARGS__)
#define ST_LOG_WARN(format,...)       NS_STCC StLog(__FILE__,__FUNCTION__,__LINE__,NS_STCC LOG_LEVEL_WARN,format, ##__VA_ARGS__)‰
#define ST_LOG_ERROR(format,...)      NS_STCC StLog(__FILE__,__FUNCTION__,__LINE__,NS_STCC LOG_LEVEL_ERROR,format, ##__VA_ARGS__)
#endif //Debug switch


//////////////////////////////////////////
//LOG PRINT FORMATE
//////////////////////////////////////////
#if defined(__GNUC__) && (__GNUC__ >= 4)
#define ST_FORMAT_PRINTF(formatPos, argPos) __attribute__((__format__(__printf__, formatPos, argPos)))

#elif defined(__has_attribute)
#if __has_attribute(format)
#define ST_FORMAT_PRINTF(formatPos, argPos) __attribute__((__format__(__printf__, formatPos, argPos)))
#endif // __has_attribute(format)

#else
#define ST_FORMAT_PRINTF(formatPos, argPos)

#endif

NS_STCC_BEGIN

enum LogLevel
{
    LOG_LEVEL_TEXT,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
};

void ST_FORMAT_PRINTF(5,6) StLog(const char *file,const char *function,int line,int logLevel,const char * format,...);

void StLogArray(const float* array,const int size,char di);

NS_STCC_END

#pragma GCC visibility pop

#endif /* STccLog_hpp */
