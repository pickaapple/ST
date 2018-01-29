//
//  STccListArray_In.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccListArray_In_hpp
#define STccListArray_In_hpp

#include <string.h>

template <class E /*Element*/>
bool ListArray<E>::FindIndexByElement(const e_t& e,size_t* index) const
{
    size_t i;
    FOREACH_ARRAY(i, _length)
    {
        if (e == _data[i])
        {
            *index = i;
            return true;
        }
    }
    return false;
}

template <class E /*Element*/>
const E* ListArray<E>::GetElements() const
{
    return _data;
}

template <class E /*Element*/>
size_t ListArray<E>::Length() const
{
    return _length;
}

template <class E /*Element*/>
bool ListArray<E>::IsEmpty() const
{
    return 0 == _length;
}

template <class E /*Element*/>
E* ListArray<E>::At(size_t index) const
{
    if(index < _length)
        return nullptr;
    return &operator[](index);
}

template <class E /*Element*/>
E& ListArray<E>::AddAtFirst(const e_t &e)
{
    if (_length >= _capacity)
    {
        size_t newCapacity = 1 + _capacity + (_capacity >> 1);
        e_t* newData = NewData(newCapacity);
        memcpy(newData + 1, _data, sizeof(e_t) * _capacity);
        DeleteData(_data);
        _data = newData;
        _capacity = newCapacity;
    }
    return _data[0] = e;
}

template <class E /*Element*/>
E& ListArray<E>::AddAtLast(const e_t &e)
{
    if(_length >= _capacity)
    {
        size_t newCapacity = 1 + _capacity + (_capacity >> 1);
        e_t* newData = NewData(newCapacity);
        memcpy((void*)newData,(void*)_data,_capacity * sizeof(e_t));
        DeleteData(_data);
        _data = newData;
        _capacity = newCapacity;
    }
    return _data[_length++] = e;
}
template <class E /*Element*/>
bool ListArray<E>::Injure(const e_t es[], size_t size)
{
    if (_capacity < size + _length)
    {
        size_t newCapacity = size + _length + (_capacity >> 1);
        e_t* newData = NewData(newCapacity);
        memcpy(newData, _data, sizeof(e_t) * _length);
        DeleteData(_data);
        _data = newData;
        _capacity = newCapacity;
    }
    memcpy(_data + _length, es, sizeof(e_t) * size);
    _length += size;
    return true;
}
template <class E /*Element*/>
// replace all data
bool ListArray<E>::ReplaceByIndex(const e_t& es, size_t index)
{
    if (index >= _length)
    {
        return false;
    }
    _data[index] = es;
    return true;
}
template <class E /*Element*/>
// replace all data
bool ListArray<E>::ReplaceAll(const e_t es[], size_t size)
{
    if(_capacity < size){
        size_t newCapacity =size + (_capacity >> 1);
        e_t* newData = NewData(newCapacity);
        DeleteData(_data);
        _data = newData;
        _capacity = newCapacity;
    }
    _length = size;
    memcpy(_data, es, sizeof(e_t) * size);
    return true;
}
template <class E /*Element*/>
//include start element
bool ListArray<E>::Remove(size_t start,size_t length)
{
    if (start > _length)
        return false;
    if (start + length >= _length)
    {
        _length = start;
        return true;
    }
    size_t end = start + length;
    memcpy(_data + start, _data + end, _length - end);
    _length -= length;
    return true;
}
template <class E /*Element*/>
bool ListArray<E>::Remove(size_t index)
{
    return Remove(index,1);
}
template <class E /*Element*/>
E ListArray<E>::RemoveLast()
{
    return _data[--_length];
}
template <class E /*Element*/>
E* ListArray<E>::NewData(size_t n)
{
    e_t* ret = new e_t[n];
    return ret;
}
template <class E /*Element*/>
void ListArray<E>::DeleteData(e_t* data)
{
    delete data;
}
template <class E /*Element*/>
E& ListArray<E>::operator [] (size_t index) const
{
    ASSERT(index < _length);
    return _data[index];
}
template <class E /*Element*/>
bool ListArray<E>::operator == (const ListArray& list) const
{
    size_t i;
    FOREACH_ARRAY(i,_length)
    {
        if(At(i) != list.At(i))
            return false;
    }
    return true;
}

template <class E /*Element*/>
void ListArray<E>::Initialize(size_t capacity){
    _data = NewData(capacity);
}

template <class E /*Element*/>
void ListArray<E>::Initialize(const e_t es[],size_t length, size_t capacity){
    ASSERT(es);
    ASSERT(length <= capacity);
    Initialize(capacity);
    ReplaceAll(es, length);
}

template <class E /*Element*/>
ListArray<E>::ListArray(const e_t es[], size_t length, size_t capacity)
:_capacity(capacity)
,_length(length)
,_data(nullptr)
{
    Initialize(es, length, capacity);
}
template <class E /*Element*/>
ListArray<E>::ListArray(size_t capacity)
:_capacity(capacity)
,_length(0)
,_data(nullptr){
    Initialize(capacity);
}
template <class E /*Element*/>
ListArray<E>::ListArray()
:_capacity(10)
,_length(0)
, _data(nullptr) {
    Initialize(_capacity);
}


#endif /* STccListArray_In_hpp */
