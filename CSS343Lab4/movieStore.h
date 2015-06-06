//
//  movieStore.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__movieStore__
#define __CSS343Lab4__movieStore__

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "HashTable.h"
#include "movieFactory.h"
#include "instructionFactory.h"
#include "customer.h"

using namespace std;

class InstructionFactory;
class MovieFactory;

class MovieStore {
    friend class Borrow;
    friend class Return;
    friend class History;
public:
    MovieStore();
    ~MovieStore();
    
    void buildMovieDepository(ifstream&);
    void buildCustomerDepository(ifstream&);
    void processInstruction(ifstream&);
    
private:
    const int TYPESIZE = 26;
    BSTree** moviesDatabase;
    HashTable<Customer*> customers;
    MovieFactory* moviefactory;
    InstructionFactory* instructionFactory;
};

#endif /* defined(__CSS343Lab4__movieStore__) */
