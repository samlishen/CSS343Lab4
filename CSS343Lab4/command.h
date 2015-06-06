//
//  command.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__command__
#define __CSS343Lab4__command__

#include "instruction.h"

class Command : public Instruction {
public:
    Command();
    virtual ~Command();
    
    virtual string toString() const = 0;
    
protected:
    Customer* customer;
    static MovieFactory movieFactory;
};

#endif /* defined(__CSS343Lab4__command__) */