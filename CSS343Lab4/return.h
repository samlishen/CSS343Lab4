//
//  return.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__return__
#define __CSS343Lab4__return__

#include "instruction.h"

class Return : public Instruction {
public:
    Return();
    virtual ~Return();
    
    virtual Instruction* create(MovieStore*, ifstream&) const;
    virtual string toString() const;
    virtual char getType() const;
    
private:
    Movie* movie;
    char mediaType;
};

#endif /* defined(__CSS343Lab4__return__) */
