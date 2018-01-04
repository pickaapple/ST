//
//  STccLinkedList.cpp
//  STCommenCode
//
//  Created by Apple on 2017/3/28.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "structure/STccListLinked.hpp"

NS_STCC NodeLinked::NodeLinked()
{
}

NS_STCC NodeLinked::NodeLinked(void* p)
{
    _payload = p;
}

NS_STCC NodeLinked::~NodeLinked()
{
    
}
//////////////////////////////////////////

size_t NS_STCC ListLinked::GetLength(){
    return _length;
}

NS_STCC NodeLinked* NS_STCC ListLinked::FindNode(void* payload)
{
    NodeLinked* current = _first;
    while(current != 0)
    {
        if(current->_payload == payload)
            return current;
        current = current->_next;
    }
    return nullptr;
}

void NS_STCC ListLinked::PushBack(NodeLinked *ptr)
{
    ptr -> _next = 0;
    _end -> _next = ptr;
    _end =  ptr;
    
    ++_length;
}

void NS_STCC ListLinked::PushFront(NodeLinked *ptr)
{
    ptr    -> _next = _first -> _next;
    _first -> _next = ptr;
    
    ++_length;
}

void* NS_STCC ListLinked::Remove(NodeLinked* node)
{
    NodeLinked* current = _first -> _next;
    void *ret = 0;
    //if the node is first one
    if(current == node && current != 0)
    {
        ret = current -> _payload;
        _first -> _next = current -> _next;
        SAFE_DELETE(current);
        --_length;
        return ret;
    }
    
    NodeLinked* preCur = _first;
    while(current != 0)
    {
        if(current == node)
        {
            ret = current -> _payload;
            preCur -> _next = current -> _next;
            SAFE_DELETE(current);
            --_length;
            return ret;
        }
        preCur  = current;
        current = current->_next;
    }
    return ret;
}

void NS_STCC ListLinked::RemoveByPayload(void* payload)
{
    NodeLinked *current = _first -> _next;
    if(current == 0)
        return;
    //if the node is first one
    if(current -> _payload == payload)
    {
        _first -> _next = current -> _next;
        SAFE_DELETE(current);
        --_length;
        return;
    }
    
    NodeLinked* preCur = _first;
    while(current != 0)
    {
        if(current -> _payload == payload)
        {
            preCur -> _next = current -> _next;
            SAFE_DELETE(current);
            --_length;
            return;
        }
        preCur  = current;
        current = current->_next;
    }
    --_length;
}

void NS_STCC ListLinked::InsertAfter(NodeLinked *current,NodeLinked *added)
{
    added   -> _next = current->_next;
    current -> _next = added;
}

NS_STCC ListLinked::ListLinked()
{
    _end = _first = NewData();
}

NS_STCC ListLinked::~ListLinked()
{
    NodeLinked* next;
    while(_first != 0)
    {
        next = _first -> _next;
        delete _first;
        _first = next;
    }
    _first = 0;
}

NS_STCC NodeLinked* NS_STCC ListLinked::NewData()
{
    return new NodeLinked();
}

void NS_STCC ListLinked::DeleteData(NodeLinked* p)
{
    delete p;
}

