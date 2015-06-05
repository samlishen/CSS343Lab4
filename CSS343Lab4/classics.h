//
//  classics.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__classics__
#define __CSS343Lab4__classics__

#include "movie.h"

class Classics : public Movie {
    friend ostream& operator << (ostream& outStream, const Classics& classics);
public:
    Classics();
    virtual ~Classics();
    
    virtual Movie* create(ifstream&) const;
    virtual char getType() const;
    virtual string toString() const;
    
    bool operator < (const Movie&) const;
    bool operator == (const Movie&) const;
    bool operator > (const Movie&) const;
    
protected:
    string actorFirstName, actorLastName;
    int month;
};

#endif /* defined(__CSS343Lab4__classics__) */
