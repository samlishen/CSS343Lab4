//
//  instructionFactory.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/5.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__instructionFactory__
#define __CSS343Lab4__instructionFactory__

#include "instruction.h"

class MovieStore;
class Instruction;

class InstructionFactory {
public:
    InstructionFactory();
    ~InstructionFactory();
    
    Instruction* createIt(char, MovieStore*, ifstream&) const;
private:
    const int FACTORYSIZE = 26;
    Instruction** instructions;
    static int hash(char ch);
};

#endif /* defined(__CSS343Lab4__instructionFactory__) */
