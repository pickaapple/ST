//
//  STccListArray.hpp
//  STCommenCode
//
//  Created by yhys on 2017/6/13.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccListArray_hpp
#define STccListArray_hpp

#include "STccMacro.hpp"
#include "STccMallocation.hpp"


#pragma GCC visibility push(default)

NS_STCC_BEGIN

template <class E /*Element type*/>
class ListArray
{
    
public:
    typedef E	e_t;
    
    inline bool FindIndexByElement(const e_t& e,size_t* index) const;
    
    inline const E* GetElements()   const;
    
    inline size_t Length()          const;
    
    inline bool IsEmpty()           const;
    
    inline e_t* At(size_t index)    const;
    
    // add one element at first
    inline e_t& AddAtFirst(const e_t &e);
    
    // add one element at last
    inline e_t& AddAtLast(const e_t &e);
    
    inline bool Injure(const e_t es[], size_t size);
    
    // replace all data
    inline bool ReplaceByIndex(const e_t& es, size_t index);
    
    // replace all data
    inline bool ReplaceAll(const e_t es[], size_t size);
    
    //include start element
    inline bool Remove(size_t start,size_t length);
    
    inline bool Remove(size_t index);
    
    inline e_t RemoveLast();
    
    inline e_t& operator [] (size_t index)          const;
    
    inline bool operator == (const ListArray& list) const;
    
    inline explicit ListArray();
    
    inline explicit ListArray(size_t capacity);
    
    inline explicit ListArray(const e_t es[], size_t length, size_t capacity);
    
private:
    inline void Initialize(size_t capacity);
    
    inline void Initialize(const e_t es[],size_t length, size_t capacity);
    
    inline e_t* NewData(size_t n);
    
    inline void DeleteData(e_t* data);
    
public:
    e_t* _data;
    
    size_t _length;
    
    size_t _capacity;
};

#include "STccListArray_In.hpp"

NS_STCC_END

#pragma GCC visibility pop

#endif /* STccListArray_hpp */
