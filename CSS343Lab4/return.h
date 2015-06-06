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

class Return : public Command {
public:
    Return();
    virtual ~Return();
    
    virtual Instruction* create(MovieStore*, ifstream&) const;
    virtual string toString() const;
    
private:
    Movie* movie;
    char mediaType;
};

#endif /* defined(__CSS343Lab4__return__) */
