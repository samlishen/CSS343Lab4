//
//  instruction.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__instruction__
#define __CSS343Lab4__instruction__

#include <fstream>
#include <iostream>
#include "movieStore.h"
using namespace std;

class MovieStore;
class Customer;

class Instruction {
public:
    Instruction();
    virtual ~Instruction();
    
    virtual Instruction* create(MovieStore*, ifstream&) const = 0;
    virtual string toString() const = 0;
    virtual char getType() const = 0;
    
protected:
    Customer* customer;
    virtual int hash(char) const;
    MovieFactory* movieFactory;
};

#endif /* defined(__CSS343Lab4__instruction__) */
