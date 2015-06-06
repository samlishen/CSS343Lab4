//
//  history.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/5.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "history.h"
#include "movieStore.h"

History:: History() {
    
}

History:: ~History() {
    
}

Instruction* History:: create(MovieStore* store, ifstream& infile) const {
    int id;
    infile >> id;
    Customer* custormerToBeProcessed;
    if((store->customers).retrieve(id, custormerToBeProcessed)) {
        custormerToBeProcessed->displayHistory();
    }
    return NULL;
}

char History:: getType() const {
    return 'H';
}

string History:: toString() const {
    return "";
}
