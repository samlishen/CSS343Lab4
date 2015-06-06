//
//  BSTree.h
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __CSS343Lab4__BSTree__
#define __CSS343Lab4__BSTree__
#include "movie.h"
#include <iostream>
using namespace std;

class BSTree {
public:
    BSTree();   //default constructor
    ~BSTree();  //destructor
    bool insert(Movie*);    //insert function
    bool retrieve(Movie*, Movie*&); //retrieve function
    void clear();//remove all
    void display() const;   //display function
    
private:
    //treeNode
    struct Node{
        Movie* pDate;
        Node* left;
        Node* right;
    };
    //head of the tree
    Node* head;
    
    
    bool insert(Movie*, Node*&);//helper function for insert
    bool retrieve(Movie*, Movie*&, Node*);//helper function for retrieve
    void clear(Node*);//helper function for destructor
    void display(Node*) const;//helper function for display
};

#endif /* defined(__CSS343Lab4__BSTree__) */
