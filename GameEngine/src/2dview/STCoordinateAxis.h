//
//  CoordinateAxis.h
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef CoordinateAxis_h
#define CoordinateAxis_h

#include "ST2DViewMacros.h"
#include "STPrimitiveData.h"

NS_VIEW2D_BEGIN

class _CoordinateAxis{
public:
    int orign_x;
    int orign_y;
    int orign_z;
    bool di_po_gl_x;
    bool di_po_gl_y;
    bool di_po_gl_z;
    _CoordinateAxis();
    void makeOutCoor(float *outCoor,const int &local_x,const int &local_y,const int &local_z);
    void makeOutCoors(float **outCoors,const _PrimitiveData* prim,const char &dire);
    void makeOutCoors(float (*outCoors)[3],const _PrimitiveData* prim,const char &dire);
    inline int orign_coor(const int &dire){
        switch (dire) {
            default:
            case 0:
                return orign_x;
            case 1:
                return orign_y;
            case 2:
                return orign_z;
        }
    };
    inline bool orign_dire(const int &dire){
        switch (dire) {
            default:
            case 0:
                return di_po_gl_x;
            case 1:
                return di_po_gl_y;
            case 2:
                return di_po_gl_z;
        }
    };
};

NS_VIEW2D_END

#endif /* CoordinateAxis_h */
