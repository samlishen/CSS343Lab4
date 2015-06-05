//
//  borrow.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "borrow.h"

Instruction* Borrow:: create(ifstream& infile) const {
    Borrow* newInstruction = new Borrow;
    int id;
    char mediaT, movieT;
    infile >> id;
    infile >> mediaT;
    infile >> movieT;
    newInstruction->customer = id;
    newInstruction->mediaType = mediaT;
    
    Movie* theMovie = movieFactory.createIt(movieT, infile);
    newInstruction->movie = theMovie;
    
    return newInstruction;
}

bool Borrow:: process(BSTree** movieTree, HashTable<Customer>customerList) {
    if(movieTree[hash(mediaType)] == NULL) return false;
    BSTree* tree = movieTree[hash(mediaType)];
    Movie* m;
    Customer* c = customerList.retrieve(customer);
    if (tree->retrieve(movie, m)) {
        if (m->borrowType(mediaType, 1)) {
            c->addOnHold(m);
            return true;
        }
    }
    return false;
}

string Borrow:: toString() const {
    return to_string(mediaType) + "\tBorrow\t" + movie->toString();
}