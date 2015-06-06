//
//  history.cpp
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#include "history.h"
#include "movieStore.h"


/**----------------------------------------------------------------------
 constructor
 ----------------------------------------------------------------------*/
History:: History() {
    
}


/**----------------------------------------------------------------------
 destructor
 ----------------------------------------------------------------------*/
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
