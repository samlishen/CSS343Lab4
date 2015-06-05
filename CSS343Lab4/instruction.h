//
//  instruction.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__instruction__
#define __CSS343Lab4__instruction__

#include <fstream>
#include <iostream>
using namespace std;

class Instruction {
public:
    Instruction();
    virtual ~Instruction();
    
    virtual Instruction* create(fstream&) const;
    
private:
    virtual int hash(char) const;
};

#endif /* defined(__CSS343Lab4__instruction__) */
