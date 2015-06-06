//
//  BSTree.cpp
//  CSS343Lab4
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#include "BSTree.h"

/**----------------------------------------------------------------------
 default constructor
 ----------------------------------------------------------------------*/
BSTree:: BSTree() {
    
}

/**----------------------------------------------------------------------
 destructor
 ----------------------------------------------------------------------*/
BSTree:: ~BSTree() {
    //clear();
}

/**----------------------------------------------------------------------
 insert function
 basically just call the helper function for insert
 return true if the input data does not already in the tree.
 return false if not
 This is to prevent duplicate in tree
 ----------------------------------------------------------------------*/
bool BSTree:: insert(Movie* m) {
    return insert(m, head);
}

/**----------------------------------------------------------------------
 retrieve function
 basically just call helper function for retrieve
 return true if input target does exist in the tree. Also, save the data
 in "item" parameter.
 return false if cannot be found.
 ----------------------------------------------------------------------*/
bool BSTree:: retrieve(Movie* target, Movie*& item) {
    return retrieve(target, item, head);
}

/**----------------------------------------------------------------------
 helper function for destructor
 ----------------------------------------------------------------------*/
void BSTree:: clear() {
    clear(head);
}

/**----------------------------------------------------------------------
insert helper function
 Compare the movie object in different node, return false if there is 
 duplicate. return true and insert if there is not duplicate.
 ----------------------------------------------------------------------*/
bool BSTree:: insert(Movie* m, Node* & node) {
    
    if(node==NULL){
        Node* n=new Node();
        n->pDate=m;
        n->left=NULL;
        n->right=NULL;
        node=n;
        return true;
    }
    
    if(*(node->pDate)==*m){
        return false;
    }
    if(*(node->pDate)>*m){
        return insert(m,node->left);
    }
    if(*(node->pDate)<*m){
        return insert(m,node->right);
    }
    return false;
}
/**----------------------------------------------------------------------
 retrieve helper function
 return true if the target exist and store the data in m parameter
 return false if not.
 ----------------------------------------------------------------------*/
bool BSTree:: retrieve(Movie* t, Movie*& m, Node* node) {
    if (node == NULL) {
        return false;
    }
    if (*t == *(node->pDate)) {
        m = node->pDate;
        return true;
    }
    if (*(node->pDate) > *t) {
        return retrieve(t, m, node->left);
    }
    if (*(node->pDate) < *t) {
        return retrieve(t, m, node->right);
    }
    return false;
}
/**----------------------------------------------------------------------
 destructor helper function
 ----------------------------------------------------------------------*/
void BSTree:: clear(Node* node) {
    if (node == NULL) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node->pDate;
}
/**----------------------------------------------------------------------
 display all info
 ----------------------------------------------------------------------*/
void BSTree:: display() const {
    display(head);
}
/**----------------------------------------------------------------------
 display helper function
 print from left to right
 ----------------------------------------------------------------------*/
void BSTree:: display(Node* node) const {
    if (node == NULL) {
        return;
    }
    display(node->left);
    cout << node->pDate->toString() << endl;
    display(node->right);
}