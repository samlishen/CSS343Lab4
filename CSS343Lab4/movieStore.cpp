//
//  movieStore.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "movieStore.h"

MovieStore:: MovieStore() {
    moviesDatabase = new BSTree*[TYPESIZE];
}

MovieStore:: ~MovieStore() {
    
}

void MovieStore:: buildMovieDepository(ifstream& infile) {
    while (true) {
        char type;
        infile >> type;
        if (infile.eof()) {
            return;
        }
        Movie* newMovie = moviefactory.createIt(type, infile);
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