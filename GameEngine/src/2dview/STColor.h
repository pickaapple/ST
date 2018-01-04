//
//  Color.h
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef Color_h
#define Color_h

#include "ST2DViewMacros.h"

NS_VIEW2D_BEGIN

class _Color{
public:
    float red;
    float green;
    float blue;
    float alpha;
    _Color();
    _Color(const _Color& copy);
    _Color(const float &r,const float &g,const float &b,const float &a);
};

NS_VIEW2D_END

#endif /* Color_h */
