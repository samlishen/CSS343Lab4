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
#include "movieStore.h"
using namespace std;

class Instruction {
public:
    Instruction();
    virtual ~Instruction();
    
    virtual Instruction* create(MovieStore* ,fstream&) const = 0;
    
protected:
    virtual int hash(char) const;
};

#endif /* defined(__CSS343Lab4__instruction__) */
