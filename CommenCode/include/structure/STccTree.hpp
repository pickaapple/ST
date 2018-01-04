//
//  STccTree.hpp
//  STCommenCode
//
//  Created by yhys on 2017/6/19.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccTree_hpp
#define STccTree_hpp

#include "STccMacro.hpp"
#include "STccMallocation.hpp"
#include "STccListArray.hpp"

#pragma GCC visibility push(default)

NS_STCC_BEGIN

//////////////////////////////////////////
//Interface
template<class P /*Payload*/>
class INodeTree
{
public:
    typedef P payload_type;
    
    virtual INodeTree<payload_type>*   GetFirstChild()   const = 0;
    
    virtual INodeTree<payload_type>*   GetRightBrother() const = 0;
    
    virtual bool    AddChild(INodeTree<payload_type>* node)    = 0;
    
    INodeTree();
    
    virtual ~INodeTree();
    
    bool operator ==    (const payload_type& payload) const;
    
    bool operator >     (const payload_type& payload) const;
    
    bool operator <     (const payload_type& payload) const;
public:
    payload_type    _payload;
    
    INodeTree*      _parent;
    
    uint16_st       _index;
};

//////////////////////////////////////////

template<class P /*Payload*/>
class NodeTrie
:INodeTree<P>
{
public:
    typedef P payload_type;
    
    INodeTree<payload_type>* GetFirstChild()   const override;
    
    INodeTree<payload_type>* GetRightBrother() const override;
    
    bool AddChild(INodeTree<payload_type>* node)     override;
    
    NodeTrie();
    
    virtual ~NodeTrie();
    
protected:
    ListArray<INodeTree<payload_type>*> _children;
};

//////////////////////////////////////////

template<class P /*Payload*/>
class NodeBTree
:INodeTree<P>
{
public:
    typedef P payload_type;
    
    INodeTree<payload_type>* GetFirstChild()   const   override;
    
    INodeTree<payload_type>* GetRightBrother() const   override;
    
    bool AddChild(INodeTree<payload_type>* node)       override;
    
    NodeBTree();
    
    virtual ~NodeBTree();
    
public:
    INodeTree<payload_type>* _left;
    
    INodeTree<payload_type>* _right;
    
};

//////////////////////////////////////////

template<class P /*Payload*/>
class Trie
{
public:
    typedef P payload_type;
    
    Trie();
    
    virtual ~Trie();
    
private:
    void Initialize();
    
    INodeTree<payload_type>* NewData(const payload_type &payload);
    
    void DeleteData(INodeTree<payload_type>* p);
    
protected:
    NodeTrie<payload_type> _root;
};

#include "structure/STccTree_In.hpp"

NS_STCC_END

#pragma GCC visibility pop

#endif /* STccTree_hpp */
