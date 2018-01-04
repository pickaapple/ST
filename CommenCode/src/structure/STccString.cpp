//
//  STccString.cpp
//  STCommenCode
//
//  Created by yhys on 2017/6/19.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "structure/STccString.hpp"

size_t NS_STCC strLen(const char *str)
{
    if (0 == str)
        return 0;
    size_t length = 0;
    while ('\0' != *(str++))
        ++length;
    return length;
}

size_t NS_STCC strCount(const char *strs[],const char endChar)
{
    size_t length = 0;
    while (endChar != **(strs++)) // get the first char of string
        ++length;
    return length;
}
