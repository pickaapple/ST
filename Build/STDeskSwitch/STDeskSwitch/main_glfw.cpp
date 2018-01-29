//
//  main_glfw.cpp
//  STDeskSwitch
//
//  Created by Apple on 2018/1/27.
//  Copyright © 2018年 ST Studio. All rights reserved.
//

#include "GLFW/glfw3.h"
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
int main(int argc, const char *argv[])
{
    if(!glfwInit())
        return 0;
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello", nullptr, nullptr);
    glfwSetKeyCallback(window, key_callback);
    if(!window)
        return 0;
    while(!glfwWindowShouldClose(window)){
        
    }
    
}
