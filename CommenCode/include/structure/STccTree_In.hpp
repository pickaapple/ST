//
//  STccTree_In.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccTree_In_hpp
#define STccTree_In_hpp

//////////////////////////////////////////

template<class P /*Payload*/>
bool INodeTree<P>::operator < (const payload_type& payload) const
{
    return _payload < payload;
}

template<class P /*Payload*/>
bool INodeTree<P>::operator > (const payload_type& payload) const
{
    return _payload > payload;
}

template<class P /*Payload*/>
bool INodeTree<P>::operator == (const payload_type& payload) const
{
    return _payload = payload;
}

//////////////////////////////////////////

template<class P /*Payload*/>
INodeTree<P>* NodeTrie<P>::GetFirstChild() const
{
    return _children.At(0);
}

template<class P /*Payload*/>
INodeTree<P>* NodeTrie<P>::GetRightBrother() const
{
    ASSERT(INodeTree<P>::_parent);
    NodeTrie<P> *treeNode = dynamic_cast<NodeTrie<P>*>(INodeTree<P>::_parent);
    if (treeNode)
        return treeNode->_Children[INodeTree<P>::_index + 1];
    return INodeTree<P>::_parent->GetRightBrother();
}

template<class P /*Payload*/>
bool NodeTrie<P>::AddChild(INodeTree<P>* node)
{
    _children.AddAtLast(node)->INodeTree<P>::_index = INodeTree<P>::_index + 1;
    return true;
}

//////////////////////////////////////////

template<class P /*Payload*/>
INodeTree<P>* NodeBTree<P>::GetFirstChild() const
{
    return _left;
}

template<class P /*Payload*/>
INodeTree<P>* NodeBTree<P>::GetRightBrother() const
{
    ASSERT(INodeTree<P>::_parent);
    return INodeTree<P>::_parent -> _right;
}

template<class P /*Payload*/>
bool NodeBTree<P>::AddChild(INodeTree<P> *node)
{
    if(!_left)
    {
        _left = node;
        _left->_Index = 0;
        return true;
    }
    if(!_right)
    {
        _right = node;
        _right->_Index = 1;
        return true;
    }
    
    return false;
}

template<class P /*Payload*/>
NodeBTree<P>::NodeBTree()
{
    
}

template<class P /*Payload*/>
NodeBTree<P>::~NodeBTree()
{
    
}

//////////////////////////////////////////

template<class P /*Payload*/>
Trie<P>::Trie()
{
    Initialize();
}

template<class P /*Payload*/>
Trie<P>::~Trie()
{
}

//private function

template<class P /*Payload*/>
void Trie<P>::Initialize()
{
}

template<class P /*Payload*/>
INodeTree<P>* Trie<P>::NewData(const P &payload)
{
    return new NodeTrie<P>(payload);
}

template<class P /*Payload*/>
void Trie<P>::DeleteData(INodeTree<P> *p)
{
    delete p;
}

#endif /* STccTree_In_hpp */
