//
//  return.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "return.h"
#include "movieStore.h"

Return:: Return() : Instruction() {
    
}

Return:: ~Return() {
    
}

Instruction* Return:: create(MovieStore* store, ifstream& infile) const {
    int id;
    infile >> id;
    Customer* customerToBeProcessed = NULL;
    if (store->customers.retrieve(id, customerToBeProcessed)) {
        char mediaT, movieT;
        Movie* movieToBeSearch = NULL;
        infile >> mediaT >> movieT;
        movieToBeSearch = movieFactory->createSimpleIt(movieT, infile);
        if (movieToBeSearch != NULL) {
            Movie* movieToBeProcessed = NULL;
            if(customerToBeProcessed->
               getOwn(movieToBeSearch, movieToBeProcessed)) {
                movieToBeProcessed->returnType(mediaT, 1);
                customerToBeProcessed->deleteOwn(movieToBeProcessed);
                Return* newInstruction = new Return;
                newInstruction->customer = customerToBeProcessed;
                newInstruction->movie = movieToBeProcessed;
                newInstruction->mediaType = mediaT;
                newInstruction->customer->addHistory(newInstruction);
                return newInstruction;
            }
        }
    }
    string reading;
    getline(infile, reading);
    return NULL;
}

string Return:: toString() const {
    return  movie->getMediaTypeName(mediaType) + "\tReturn\t" + movie->toString();
}

char Return:: getType() const {
    return 'R';
}