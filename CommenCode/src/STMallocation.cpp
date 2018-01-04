//
//  STccMallocation.cpp
//  STCommenCode
//
//  Created by yhys on 2017/6/18.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STccMallocation.hpp"

#include "STccLog.hpp"

//////////////////////////////////////////

void* NS_STCC Mallocation::New(size_t size)
{
    return malloc(size);
}

void NS_STCC Mallocation::Delete(void* p)
{
    free(p);
}

void NS_STCC Mallocation::FatalProcessOutOfMemory()
{
    ST_LOG_ERROR("Fatal Process Out Of Memory");
    abort();
}

//////////////////////////////////////////

void* NS_STCC ObjectCtrl::operator new(size_t size)
{
    void* p = Mallocation::New(size);
    if(p == NULL) Mallocation::FatalProcessOutOfMemory();
    return p;
}

void* NS_STCC ObjectCtrl::operator new[](size_t size)
{
    void* p = Mallocation::New(size);
    if(p == NULL) Mallocation::FatalProcessOutOfMemory();
    return p;
}

void NS_STCC ObjectCtrl::operator delete(void *p)
{
    Mallocation::Delete(p);
}

void NS_STCC ObjectCtrl::operator delete[](void *p)
{
    Mallocation::Delete(p);
}
