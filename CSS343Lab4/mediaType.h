//
//  mediaType.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__mediaType__
#define __CSS343Lab4__mediaType__

#include <string>
using namespace std;

class MediaType {
public:
    MediaType();
    MediaType(string);
    MediaType(string, int);
    ~MediaType();
    
    string getTypeName() const;
    int getCurrent() const;
    int getMax() const;
    bool isEnough(int) const;
    bool borrowType(int);
    bool returnType(int);
    bool addType(int);
    
protected:
    string typeName;
    int current;
    int max;
};

#endif /* defined(__CSS343Lab4__mediaType__) */
