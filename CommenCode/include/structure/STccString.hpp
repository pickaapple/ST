//
//  STccString.hpp
//  STCommenCode
//
//  Created by yhys on 2017/6/19.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccString_hpp
#define STccString_hpp

#include "STccListArray.hpp"
#include "STccMallocation.hpp"

#pragma GCC visibility push(default)

NS_STCC_BEGIN

template <class E /*Element*/>
class String :
protected ListArray<E>
{
public:
    const E* GetChar() const;
    
    size_t Length() const;				//character count expect null character
    
    bool Append(const String<E> &str);
    
    //append string whether the elements is or not end of '\0'
    bool Append(const E* elements, size_t size);
    
    bool Append(const E element);
    
    String();
    
    String(const E* e);
    
    String(const E* e, size_t length);
    
    virtual ~String() {};
};

size_t strLen(const char *str);

size_t strCount(const char *strs[], const char endChar);

#include "STccString_In.hpp"

typedef String<char> string;


NS_STCC_END

#pragma GCC visibility pop

#endif /* STccString_hpp */
