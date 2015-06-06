//
//  mediaType.h
//  CSS343Lab4
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







//
//  mediaType.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "mediaType.h"
/**----------------------------------------------------------------------
 default Constructor
 set value to bad value
 ----------------------------------------------------------------------*/
MediaType:: MediaType() {
    typeName="This is null";
    current=-1;
    max=-1;
}
/**----------------------------------------------------------------------
 constructor that take one string, which is typename
 set current and max inventory to 10
 ----------------------------------------------------------------------*/
MediaType:: MediaType(string type) {
    typeName = type;
    current = 10;
    max = 10;
}
/**----------------------------------------------------------------------
 constructor that take one string, which is typename, and one int, which
 is inventory number
 set current and max inventory number to user input
 ----------------------------------------------------------------------*/
MediaType:: MediaType(string type, int amount) {
    typeName = type;
    current = amount;
    max = amount;
}
/**----------------------------------------------------------------------
 destructor
 ----------------------------------------------------------------------*/
MediaType:: ~MediaType() {
    
}
/**----------------------------------------------------------------------
 return string typename
 ----------------------------------------------------------------------*/
string MediaType:: getTypeName() const {
    return typeName;
}
/**----------------------------------------------------------------------
 return current instore inventory number
 ----------------------------------------------------------------------*/
int MediaType:: getCurrent() const {
    return current;
}
/**----------------------------------------------------------------------
 return max inventory number
 ----------------------------------------------------------------------*/
int MediaType:: getMax() const {
    return max;
}
/**----------------------------------------------------------------------
 check if current inventory is enough for the input amount
 
 ----------------------------------------------------------------------*/
bool MediaType:: isEnough(int amount) const {
    return amount <= current;
}
/**----------------------------------------------------------------------
 call when customers borrow this mediatype
 return true if the store currently have enough inventory
 return false if not, and will not do any operation
 ----------------------------------------------------------------------*/
bool MediaType:: borrowType(int amount) {
    if (isEnough(amount)) {
        current -= amount;
        return true;
    }
    return false;
}
/**----------------------------------------------------------------------
 call when customers return this mediatype
 return true if customers do not return too many. (more than max inventory)
 return false if not, and will not do any operation
 ----------------------------------------------------------------------*/
bool MediaType:: returnType(int amount) {
    if (max <= current + amount) {
        current += amount;
        return true;
    }
    return false;
}
/**----------------------------------------------------------------------
 call when stores add more inventory to this media type
 the amount cannot be negative
 return false if the amount is not negative or 0, will not do any operation
 return true if not
 ----------------------------------------------------------------------*/
bool MediaType:: addType(int amount) {
    if (amount >= 0) {
        max += amount;
        current += amount;
        return true;
    }
    return false;
}





