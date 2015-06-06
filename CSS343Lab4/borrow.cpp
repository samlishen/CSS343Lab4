//
//  borrow.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "borrow.h"

Borrow:: Borrow() {
    
}

Borrow:: ~Borrow() {
    
}

Instruction* Borrow:: create(MovieStore* store, ifstream& infile) const {
    int id;
    Customer* customerToBeProcessed = NULL;
    infile >> id;
    if ((store->customers).retrieve(id, customerToBeProcessed)) {
        char mediaT, movieT;
        Movie* movieToBeSearch = NULL;
        infile >> mediaT >> movieT;
        movieToBeSearch = movieFactory.createSimpleIt(movieT, infile);
        if (movieToBeSearch == NULL) {
            delete customerToBeProcessed;
            return NULL;
        }
        Movie* movieToBeProcessed = NULL;
        if ((store->moviesDatabase)[hash(movieT)]->
            retrieve(movieToBeSearch, movieToBeProcessed)) {
            if (movieToBeProcessed->borrowType(mediaT, 1)) {
                customerToBeProcessed->addOwn(movieToBeProcessed);
                Borrow* newInstruction;
                newInstruction->movie = movieToBeProcessed;
                newInstruction->customer = customerToBeProcessed;
                newInstruction->mediaType = mediaT;
                return newInstruction;
            }
        }
    }
    string reading;
    getline(infile, reading);
    return NULL;
}

string Borrow:: toString() const {
    return to_string(mediaType) + "\tBorrow\t" + movie->toString();
}