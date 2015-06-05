//
//  movie.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__movie__
#define __CSS343Lab4__movie__

#include "mediaType.h"
#include <fstream>


class Movie {
public:
    Movie();
    virtual ~Movie();
    
    virtual Movie* create(ifstream&) const = 0;
    
    virtual bool isEnough(char, int) const;
    virtual bool borrowType(char, int);
    virtual bool returnType(char, int);
    virtual bool addType(char, int);
    
protected:
    string director;
    string title;
    int year;
    MediaType* type[26];
    
    virtual int hash(char) const;
};

#endif /* defined(__CSS343Lab4__movie__) */
