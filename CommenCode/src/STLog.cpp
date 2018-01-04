//
//  STccLog.cpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>

#include "STccLog.hpp"

#define MAX_LOG_BUFFER_LENGTH 1024

const char* getLogLevelString(int level)
{
    switch (level)
    {
        default:
        case NS_STCC LOG_LEVEL_TEXT:
            return "TEXT";
        case NS_STCC LOG_LEVEL_INFO:
            return "INFO";
        case NS_STCC LOG_LEVEL_WARN:
            return "WARNING";
        case NS_STCC LOG_LEVEL_ERROR:
            return "ERROR";
    }
}

void NS_STCC StLog(const char *file,const char *function,int line,int logLevel,const char * format,...)
{
    int bufferSize = MAX_LOG_BUFFER_LENGTH;
    va_list args;
    va_start(args, format);
    char * buff = nullptr;
    do{
        buff = new (std::nothrow)char[bufferSize];
        if(buff==nullptr)
            return;
        int ret = vsnprintf(buff, bufferSize, format, args);
        if(ret<0){
            bufferSize *= 2;
            delete [] buff;
        }else{
            break;
        }
    }while(true);
    va_end(args);
    
#if ST_DEBUG_PRINT_FILENAME
    std::string file_temp(file);
    std::cout<<"filename:"<<file_temp.substr(file_temp.find_last_of('/'));
#endif
    
#if ST_DEBUG_PRINT_FUNCTION
    std::cout<<" function:"<<function;
#endif
    
#if ST_DEBUG_PRINT_LINE
    std::cout<<" line:"<<line;
#endif
    
#if ST_DEBUG_PRINT_FILENAME||ST_DEBUG_PRINT_LINE||ST_DEBUG_PRINT_FUNCTION
    std::cout<<std::endl;
#endif
    
    std::cout<<getLogLevelString(logLevel)<<" : "<<buff<<std::endl;
    delete [] buff;
};

void NS_STCC StLogArray(const float* array,const int size,char di)
{
    std::string s;
    std::stringstream ss;
    int i;
    for(i = 0;i < size-1;i++){
        ss <<array[i]<<di;
    }
    ss<<array[i];
    ss >> s;
    ST_LOG_INFO("%s",s.c_str());
};
