//
//  STccListLinked.hpp
//  STCommenCode
//
//  Created by Apple on 2017/3/28.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccListLinked_hpp
#define STccListLinked_hpp

#include <stdlib.h>

#include "STccMacro.hpp"

#pragma GCC visibility push(default)

NS_STCC_BEGIN

//////////////////////////////////////////
// Node 是一个转载 payload 的节点，对payload的生命周期不会造成影响。
class NodeLinked
{
public:
    NodeLinked();
    
    ~NodeLinked();
    
    NodeLinked(void* payload);
    
    void* _payload = 0;
    
    NodeLinked* _next = 0;
};


//////////////////////////////////////////
//ListLinked 是一个管理node和记录头尾node的管理者。并且有责任和义务结束node的生命周期。
class ListLinked
{
public:
    inline size_t GetLength();
    
    NodeLinked* FindNode(void* p);
    
    void PushBack(NodeLinked *node);
    
    void PushFront(NodeLinked *node);
    
    void* Remove(NodeLinked *node);
    
    void RemoveByPayload(void* payload);
    
    void InsertAfter(NodeLinked *current, NodeLinked *added);
    
    ListLinked();
    
    ~ListLinked();
    
private:
    NodeLinked* NewData();
    
    void DeleteData(NodeLinked* p);
    
public:
    size_t      _length = 0;
    
    NodeLinked* _first = 0;
    
    NodeLinked* _end = 0;
};

NS_STCC_END

#pragma GCC visibility pop

#endif /* STListLinked_hpp */
