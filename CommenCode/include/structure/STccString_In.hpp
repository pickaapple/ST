//
//  STccString_In.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccString_In_hpp
#define STccString_In_hpp

template <class E /*Element*/>
const E* String<E>::GetChar() const
{
    return ListArray<E>::_data;
}


template <class E /*Element*/>
size_t String<E>::Length() const
{
    return ListArray<E>::_length - 1;					// expect the last null character '\0'
}

template <class E /*Element*/>
bool String<E>::Append(const String<E> &str)
{
    return this -> Append(str.GetElements(),str._length);
}

template <class E /*Element*/>
bool String<E>::Append(const E* elements, size_t size)
{
    if (0 == size)
        return true;
    this -> ListArray<E>::Remove(ListArray<E>::_length - 1);	//reomve last '\0'
    this -> ListArray<E>::Injure(elements, size);
    if('\0' != elements[size - 1])
        ListArray<E>::AddAtLast('\0');		//set last '\0' if the elements is not end of '\0'
    return true;
}

template <class E /*Element*/>
bool String<E>::Append(const E element)
{
    this -> ListArray<E>::Remove(ListArray<E>::_length - 1);	//reomve last '\0'
    this -> ListArray<E>::AddAtLast(element);
    if ('\0' != element)
        ListArray<E>::AddAtLast('\0');	//set last '\0' if the elements is not end of '\0'
    return true;
}

template <class E /*Element*/>
String<E>::String()
:ListArray<E>("\0",1,32)
{
}

template <class E /*Element*/>
String<E>::String(const E* e)
{
    size_t length = NS_STCC strLen(e);
    ListArray<E>(e, length, length << 1);
}

template<class E /*Element*/>
String<E>::String(const E* str, size_t length)
:ListArray<E>(str, length, length << 1)
{
}

#endif /* STccString_In_hpp */
