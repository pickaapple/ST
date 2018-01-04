//
//  main.cpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void* operator new[](size_t size){
    void* p = malloc(size);
    printf("all[] %zu %p \n",size,p);
    return p;
}

void* operator new(size_t size){
    printf("all %zu\n",size);
    return malloc(1);
}


class Object{
public:
    //    void* operator new[](size_t size){
    //        printf("%zu",size);
    //        return malloc(size * sizeof(void*));
    //    }
    long a;
    long b;
    Object(){
        printf("Object this:%p\n",this);
    }
    void print(){
        printf("a %ld b %ld\n",a,b);
    }
};

int main(int argc, const char * argv[]) {
//    for (int i = 0; i < 100; ++i) {
        Object* o1 = new Object[2];
        printf("o1 %p \n",o1);
        printf("%lu\n",sizeof(Object));
        o1->a = 2;
        o1->b = 3;
//        Object* o2 = new Object();
//        o2->a = 2;
//        o2->b = 3;
//        Object* o3 = new Object();
//        o3->a = 2;
//        o3->b = 3;
//        Object* o4 = new Object();
//        o4->a = 2;
//        o4->b = 3;
//        
//        o1->print();
//        o2->print();
//        o3->print();
//        o4->print();
//    }
    return 0;
}
