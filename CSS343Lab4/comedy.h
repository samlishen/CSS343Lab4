//
//  comedy.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__comedy__
#define __CSS343Lab4__comedy__

#include "movie.h"

class Comedy : public Movie{
    friend ostream& operator << (ostream&, const Comedy&);
public:
    Comedy();
    ~Comedy();
    
    virtual Movie* create(ifstream&) const;
    virtual char getType() const;
    
    virtual bool operator < (const Movie&) const;
    virtual bool operator == (const Movie&) const;
    virtual bool operator > (const Movie&) const;
};

#endif /* defined(__CSS343Lab4__comedy__) */
