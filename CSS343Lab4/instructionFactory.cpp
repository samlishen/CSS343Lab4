//
//  instructionFactory.cpp
//  CSS343Lab4
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#include "instructionFactory.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

InstructionFactory:: InstructionFactory() {
    instructions = new Instruction*[FACTORYSIZE];
    for (int i = 0; i < FACTORYSIZE; i++) {
        instructions[i] = NULL;
    }
    Borrow* borrow = new Borrow;
    History* history = new History;
    Return* retUrn = new Return;
    instructions[hash(borrow->getType())] = borrow;
    instructions[hash(history->getType())] = history;
    instructions[hash(retUrn->getType())] = retUrn;
}

InstructionFactory:: ~InstructionFactory() {
    for (int i = 0; i < FACTORYSIZE; i++) {
        if (instructions[i] != NULL) {
            delete instructions[i];
            instructions[i] = NULL;
        }
    }
    delete [] instructions;
}

Instruction* InstructionFactory::createIt(char ch, MovieStore* store, ifstream& infile) const {
    if (instructions[hash(ch)] == NULL) {
        string reading;
        getline(infile, reading);
        return NULL;
    }
    return instructions[hash(ch)]->create(store, infile);
}

int InstructionFactory:: hash(char ch) {
    return ch - 'A';
}