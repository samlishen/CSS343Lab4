//
//  borrow.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__borrow__
#define __CSS343Lab4__borrow__

#include "instruction.h"
#include "movie.h"

class Borrow : public Instruction{
public:
    Borrow();
    virtual ~Borrow();
    
    virtual Instruction* create(MovieStore*, ifstream&) const;
    virtual string toString() const;
    virtual char getType() const;
    
protected:
    Movie* movie;
    char mediaType;
};

#endif /* defined(__CSS343Lab4__borrow__) */
