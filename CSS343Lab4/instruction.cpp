//
//  instruction.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "instruction.h"


Instruction:: Instruction() {
    movieFactory = new MovieFactory;
    customer = new Customer;
}

Instruction:: ~Instruction() {
    delete movieFactory;
    movieFactory = NULL;
    delete customer;
    customer = NULL;
}

int Instruction:: hash(char ch) const {
    return ch - 'A';
}