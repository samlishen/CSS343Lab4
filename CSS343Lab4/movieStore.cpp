//
//  movieStore.cpp
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#include "movieStore.h"

MovieStore:: MovieStore() {
    moviesDatabase = new BSTree*[TYPESIZE];
    for (int i = 0; i < TYPESIZE; i++) {
        moviesDatabase[i] = new BSTree;
    }
    moviefactory = new MovieFactory;
    instructionFactory = new InstructionFactory;
}

MovieStore:: ~MovieStore() {
    for (int i = 0; i < TYPESIZE; i++) {
        delete moviesDatabase[i];
        moviesDatabase[i] = NULL;
    }
    delete [] moviesDatabase;
    moviesDatabase = NULL;
    delete moviefactory;
    moviefactory = NULL;
    delete instructionFactory;
    instructionFactory = NULL;
}

void MovieStore:: buildMovieDepository(ifstream& infile) {
    while (true) {
        char type;
        infile >> type;
        if (infile.eof()) {
            return;
        }
        Movie* newMovie = moviefactory->createIt(type, infile);
        if(newMovie == NULL) {
            string reading;
            getline(infile, reading);
            continue;
        }
        moviesDatabase[type - 'A']->insert(newMovie);
    }
}


void MovieStore:: buildCustomerDepository(ifstream& infile) {
    Customer creator;
    while (true) {
        if(infile.eof()) return;
        Customer* newCustomer = creator.create(infile);
        customers.insert(newCustomer->getID(), newCustomer);
    }
}

void MovieStore:: processInstruction(ifstream& infile) {
    while (true) {
        char type;
        infile >> type;
        if (infile.eof()) {
            return;
        }
        instructionFactory->createIt(type, this, infile);
    }
}