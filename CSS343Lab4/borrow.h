//
//  borrow.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__borrow__
#define __CSS343Lab4__borrow__

#include "command.h"

class Borrow : public Command{
public:
    Borrow();
    virtual ~Borrow();
    
    virtual Instruction* create(MovieStore*, ifstream&) const;
    virtual string toString() const;
    
protected:
    Movie* movie;
    char mediaType;
};

#endif /* defined(__CSS343Lab4__borrow__) */
