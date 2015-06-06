//
//  main.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "movieStore.h"
#include "classics.h"
#include "drama.h"
using namespace std;

int main() {
    MovieStore store;
    ifstream movie("data4movies.txt"),
    customer("data4customers.txt"),
    instruction("data4commands.txt");
    store.buildMovieDepository(movie);
    store.buildCustomerDepository(customer);
    store.processInstruction(instruction);
}
