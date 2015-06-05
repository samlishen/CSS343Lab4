//
//  drama.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__drama__
#define __CSS343Lab4__drama__

#include "movie.h"

class Drama : public Movie {
    friend ostream& operator << (ostream& outStream, const Drama& drama);
    
public:
    Drama();
    ~Drama();
    
    virtual Movie* create(ifstream&) const;
    virtual char getType() const;
    
    virtual bool operator < (const Movie&) const;
    virtual bool operator == (const Movie&) const;
    virtual bool operator > (const Movie&) const;
};

#endif /* defined(__CSS343Lab4__drama__) */
