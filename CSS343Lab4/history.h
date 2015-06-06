//
//  history.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__history__
#define __CSS343Lab4__history__

#include "instruction.h"

class History : public Instruction {
public:
    History();
    ~History();
    
    virtual Instruction* create(MovieStore*, ifstream&) const;
    virtual string toString() const;
    virtual char getType() const;
};

#endif /* defined(__CSS343Lab4__history__) */
