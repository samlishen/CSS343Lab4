//
//  movieStore.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__movieStore__
#define __CSS343Lab4__movieStore__

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "HashTable.h"
#include "movieFactory.h"
#include "customer.h"

using namespace std;

class MovieStore {
    friend class Borrow;
    friend class Return;
public:
    MovieStore();
    ~MovieStore();
    
    void buildMovieDepository(ifstream&);
    void buildCustomerDepository(ifstream&);
    
private:
    const int TYPESIZE = 26;
    BSTree** moviesDatabase;
    HashTable<Customer*> customers;
    MovieFactory moviefactory;
};

#endif /* defined(__CSS343Lab4__movieStore__) */
