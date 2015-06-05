//
//  BSTree.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __CSS343Lab4__BSTree__
#define __CSS343Lab4__BSTree__
#include "movie.h"
#include <iostream>
using namespace std;

class BSTree {
public:
    BSTree();
    ~BSTree();
    bool insert(Movie*);
    bool retrieve(Movie*, Movie*&);
    void clear();
    void display() const;
    
private:
    struct Node{
        Movie* pDate;
        Node* left;
        Node* right;
    };
    Node* head;
    bool insert(Movie*, Node*);
    bool retrieve(Movie*, Movie*&, Node*);
    void clear(Node*);
    void display(Node*) const;
};

#endif /* defined(__CSS343Lab4__BSTree__) */
