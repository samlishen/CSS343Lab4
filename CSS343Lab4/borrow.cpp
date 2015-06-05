//
//  borrow.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "borrow.h"

Instruction* Borrow:: create(MovieStore* store, ifstream& infile) const {
    int id;
    Customer* customerToBeProcessed;
    infile >> id;
    if ((store->customers).retrieve(id, customerToBeProcessed)) {
        char mediaT, movieT;
        Movie* movieToBeProcessed;
        infile
    }
}

string Borrow:: toString() const {
    return to_string(mediaType) + "\tBorrow\t" + movie->toString();
}