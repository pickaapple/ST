//
//  Color.cpp
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#include "STColor.h"

NS_VIEW2D_BEGIN

_Color::_Color():red(0),blue(0),green(0){
};
_Color::_Color(const _Color& copy){
    this->red=copy.red;
    this->green=copy.green;
    this->blue=copy.blue;
    this->alpha=copy.alpha;
};
_Color::_Color(const float &r,const float &g,const float &b,const float &a){
    red = r;
    green = g;
    blue = b;
    alpha = a;
};

NS_VIEW2D_END
