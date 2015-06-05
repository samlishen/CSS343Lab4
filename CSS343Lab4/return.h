//
//  return.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__return__
#define __CSS343Lab4__return__

#include "command.h"

class Return : Command {
public:
    Return();
    ~Return();
    
    virtual bool process(BSTree*, HashTable<Customer>);
    virtual Instruction* create(ifstream&) const;
    
private:
    Movie* movie;
    char mediaType;
};

#endif /* defined(__CSS343Lab4__return__) */
