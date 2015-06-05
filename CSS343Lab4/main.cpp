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
using namespace std;

int main() {
    MovieStore store;
    ifstream infile("data4movies.txt");
    store.buildMovieDepository(infile);
}
