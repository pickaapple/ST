//
//  STccMallocation.hpp
//  STCommenCode
//
//  Created by yhys on 2017/6/18.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccMallocation_hpp
#define STccMallocation_hpp

#include "STccMacro.hpp"

#pragma GCC visibility push(hidden)

NS_STCC_BEGIN

//////////////////////////////////////////

class Mallocation{
public:
    static void* New(size_t size);
    
    static void Delete(void* p);
    
    static void FatalProcessOutOfMemory();
};

//////////////////////////////////////////

class ObjectCtrl
{
public:
    void* operator new(size_t size);
    
    void* operator new[](size_t size);
    
    void operator delete(void* p);
    
    void operator delete[](void* p);
};

NS_STCC_END

#pragma GCC visibility pop

#endif /* STccMallocation_hpp */
