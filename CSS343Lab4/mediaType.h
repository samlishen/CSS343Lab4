//
//  mediaType.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__mediaType__
#define __CSS343Lab4__mediaType__

#include <string>
using namespace std;

class MediaType {
public:
    MediaType();    //default constructor
    MediaType(string);//constructor that only take typename
    MediaType(string, int);//constructor that take typename and max inventory
    ~MediaType();//destructor
    
    string getTypeName() const;//return typename
    int getCurrent() const;//return current inventory number
    int getMax() const;//return max inventory number
    bool isEnough(int) const;//compare current inventory with input number
    bool borrowType(int);//borrow
    bool returnType(int);//return
    bool addType(int);//add more
    
protected:
    string typeName;
    int current;
    int max;
};

#endif /* defined(__CSS343Lab4__mediaType__) */