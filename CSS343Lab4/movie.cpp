//
//  movie.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "movie.h"

Movie:: Movie() {
    type = new MediaType[TYPESIZE];
    for (int i = 0; i < 26; i++) {
        type[i] = MediaType();
    }
    type[hash('D')] = MediaType("DVD");
}

Movie:: ~Movie() {
    
}

string Movie:: toString() const {
    string retVal = title + "\t\t\t" + director + "\t\t" + to_string(year);
    return retVal;
}

string Movie:: displayType() const {
    string retVal = "";
    for (int i = 0; i < 26; i++) {
        if (type[i].getTypeName() != "") {
            retVal += "\n" + type[i].getTypeName() + ": " +
            to_string(type[i].getCurrent()) + "/" +
            to_string(type[i].getMax());
        }
    }
    return retVal;
}

bool Movie:: isEnough(char typeName, int amount) const{
    if (type[hash(typeName)].getTypeName() != "") {
        return type[hash(typeName)].isEnough(amount);
    }
    return false;
}

bool Movie:: borrowType(char typeName, int amount) {
    if (type[hash(typeName)].getTypeName() != "") {
        return type[hash(typeName)].borrowType(amount);
    }
    return false;
}

bool Movie:: returnType(char typeName, int amount) {
    if (type[hash(typeName)].getTypeName() != "") {
        return type[hash(typeName)].returnType(amount);
    }
    return false;
}

bool Movie:: addType(char typeName, int amount) {
    if (type[hash(typeName)].getTypeName() != "") {
        return type[hash(typeName)].addType(amount);
    }
    return false;
}

int Movie:: hash(char ch) const {
    return ch - 'A';
}

string Movie:: getMediaTypeName(char ch) const {
    return type[hash(ch)].getTypeName();
}