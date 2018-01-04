//
//  STPrimitiveData.cpp
//  Legend of Weapons
//
//  Created by Apple on 2017/4/7.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STPrimitiveData.h"


NS_VIEW2D_BEGIN

_PrimitiveData::_PrimitiveData(const unsigned long &prim_id,const int &vertex_count,GLint *first,GLsizei *count,const GLsizei &primcount,const GLenum &mode,float (*prim_ve_array)[3],float (*prim_co_array)[4]){
    this->prim_id = prim_id;
    this->vertex_count = vertex_count;
    this->first = first;
    this->count = count;
    this->primcount = primcount;
    this->mode = mode;
    this->prim_ve_array = prim_ve_array;
    this->prim_co_array = prim_co_array;
};
// CLASS PRIMITIVEDATA
_PrimitiveData::~_PrimitiveData(){
        ST_DELETE_ARRAY_NOT_DES_INFO(first,"DELETE[] first(GLint[]) IN PrimitiveData::~PrimitiveData() INNER STgame");
        ST_DELETE_ARRAY_NOT_DES_INFO(count,"DELETE[] count(GLsizei[]) IN PrimitiveData::~PrimitiveData() INNER STgame");
        ST_DELETE_ARRAY_NOT_DES_INFO(prim_ve_array,"DELETE[] prim_vertex_array((*float)[3]) IN PrimitiveData::~PrimitiveData() INNER STgame");
        ST_DELETE_ARRAY_NOT_DES_INFO(prim_co_array,"DELETE[] prim_color_array((*float)[4]) IN PrimitiveData::~PrimitiveData() INNER STgame");
};

NS_VIEW2D_END
////////////////////
//PUBLIC API
////////////////////
NS_ST_BEGIN

PrimitiveData createAPrimitiveData(const unsigned long& prim_id, const int& vertex_count, GLint* first, GLsizei* count, const GLsizei& primcount, const GLenum& mode, float (*prim_ve_array)[3], float (*prim_co_array)[4]){
    return ST_NEW_INFO("NEW (PrimitiveData) IN PrimitiveData ::createAPrimitiveData(+++) PUBLIC API") NS_VIEW2D _PrimitiveData(prim_id,vertex_count,first,count,primcount,mode,prim_ve_array,prim_co_array);
};
void deletePrimitiveData(PrimitiveData pd){
    ST_DELETE_DES_INFO(_PrimitiveData, (NS_VIEW2D _PrimitiveData*)pd, "DELETE (PrimitiveData) IN void deletePrimitiveData(PrimitiveData) PUBLIC API");
};
NS_ST_END
