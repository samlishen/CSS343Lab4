//
//  history.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/5.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__history__
#define __CSS343Lab4__history__

#include "command.h"

class History : public Command {
public:
    History();
    ~History();
    
    virtual Instruction* create(MovieStore*, ifstream&) const;
    virtual string toString() const;
};

#endif /* defined(__CSS343Lab4__history__) */
