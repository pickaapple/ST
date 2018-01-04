//
//  CoordinateAxis.cpp
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STCoordinateAxis.h"

NS_VIEW2D_BEGIN
_CoordinateAxis::_CoordinateAxis():
orign_x(0),
orign_y(0),
orign_z(0),
di_po_gl_x(true),
di_po_gl_y(true),
di_po_gl_z(true){
};
void _CoordinateAxis::makeOutCoor(float *outCoor,const int &local_x,const int &local_y,const int &local_z){
    *outCoor = orign_x+(di_po_gl_x?local_x:local_x);
    *(outCoor+1) = orign_y+(di_po_gl_y?local_y:-local_y);
    *(outCoor+2) = orign_z+(di_po_gl_z?local_z:-local_z);
};

void _CoordinateAxis::makeOutCoors(float **outCoors,const _PrimitiveData *prim,const char &dire){
    int i,j;
    for(j=0;j<prim->vertex_count;j++){
        for(i=0;i<dire;i++){
            outCoors[3*j][i] = orign_coor(i) + (orign_dire(i)?prim->prim_ve_array[j][i]:-prim->prim_ve_array[j][i]);
        }
    }
};
void _CoordinateAxis::makeOutCoors(float (*outCoors)[3],const _PrimitiveData *prim,const char &dire){
    int i,j;
    for(j=0;j<prim->vertex_count;j++){
        for(i=0;i<dire;i++){
            outCoors[j][i] = orign_coor(i) + (orign_dire(i)?prim->prim_ve_array[j][i]:-prim->prim_ve_array[j][i]);
        }
#if VERTEX_COOR_AFTER_COORAIXS == 1
        ST_LOG_INFO("vertex %d:(%f,%f,%f)",j,outCoors[j][0],outCoors[j][1],outCoors[j][2]);
#endif
    }
};


NS_VIEW2D_END
