//
//  movieFactory.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__movieFactory__
#define __CSS343Lab4__movieFactory__

#include "movie.h"
#include <fstream>


class MovieFactory {
public:
    MovieFactory();
    ~MovieFactory();
    
    Movie* createIt(char, ifstream&) const;
    Movie* createSimpleIt(char, ifstream&) const;
    
private:
    const int SIZE = 26;
    Movie** movies;
    
    int hash(char) const;
};

#endif /* defined(__CSS343Lab4__movieFactory__) */
