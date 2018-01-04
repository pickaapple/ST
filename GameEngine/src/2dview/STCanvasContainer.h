//
//  CanvasContainer.h
//  Legend of Weapons
//
//  Created by yhys on 2017/4/27.
//  Copyright © 2017年 STRAWBERRY FACTORY. All rights reserved.
//

#ifndef CanvasContainer_h
#define CanvasContainer_h

#include "ST2DViewMacros.h"
#include "STColor.h"
#include "STCanvas.h"

NS_VIEW2D_BEGIN

// CLASS CONTAINER
class _CanvasContainer{
private:
    NS_STR _LinkedList *canvass;
protected:
public:
    _Color base_color;
    int base_z;
    _CanvasContainer();
    ~_CanvasContainer();
    void drawAllCanvas();
    void addCanvas(_Canvas* canvas);
};

NS_VIEW2D_END

#endif /* CanvasContainer_h */
