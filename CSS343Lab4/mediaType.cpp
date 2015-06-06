//
//  mediaType.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "mediaType.h"

MediaType:: MediaType() {
    typeName = "";
    current = 0;
    max = 0;
}

MediaType:: MediaType(string type) {
    typeName = type;
    current = 10;
    max = 10;
}

MediaType:: MediaType(string type, int amount) {
    typeName = type;
    current = amount;
    max = amount;
}

MediaType:: ~MediaType() {
    
}

string MediaType:: getTypeName() const {
    return typeName;
}

int MediaType:: getCurrent() const {
    return current;
}

int MediaType:: getMax() const {
    return max;
}

bool MediaType:: isEnough(int amount) const {
    return amount <= current;
}

bool MediaType:: borrowType(int amount) {
    if (isEnough(amount)) {
        current -= amount;
        return true;
    }
    return false;
}

bool MediaType:: returnType(int amount) {
    if (max <= current + amount) {
        current += amount;
        return true;
    }
    return false;
}

bool MediaType:: addType(int amount) {
    if (amount >= 0) {
        max += amount;
        current += amount;
        return true;
    }
    return false;
}