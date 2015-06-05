//
//  movie.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "movie.h"

Movie:: Movie() {
    for (int i = 0; i < 26; i++) {
        type[i] = NULL;
    }
    type[hash('D')] = new MediaType("DVD");
}

Movie:: ~Movie() {
    for (int i = 0; i < 26; i++) {
        if (type[i] != NULL) {
            delete type[i];
            type[i] = NULL;
        }
    }
}

bool Movie:: isEnough(char typeName, int amount) const{
    if (type[hash(typeName)] != NULL) {
        return type[hash(typeName)]->isEnough(amount);
    }
    return false;
}

bool Movie:: borrowType(char typeName, int amount) {
    if (type[hash(typeName)] != NULL) {
        return type[hash(typeName)]->borrowType(amount);
    }
    return false;
}

bool Movie:: returnType(char typeName, int amount) {
    if (type[hash(typeName)] != NULL) {
        return type[hash(typeName)]->returnType(amount);
    }
    return false;
}

bool Movie:: addType(char typeName, int amount) {
    if (type[hash(typeName)] != NULL) {
        return type[hash(typeName)]->addType(amount);
    }
    return false;
}

int Movie:: hash(char ch) const {
    return ch - 'a';
}