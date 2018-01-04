//
//  STdsApplication.cpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/30.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include "STdsApplication.hpp"

NS_STDS Application* NS_STDS STApp = NULL;

void NS_STDS Application::SetDelegate(ApplicationDelegate *delegate)
{
    _delegate = delegate;
}

NS_STDS Application::Application()
{
    Init();
}

NS_STDS Application::~Application()
{
}
