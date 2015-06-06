//
//  BSTree.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "BSTree.h"

BSTree:: BSTree() {
    
}

BSTree:: ~BSTree() {
    clear();
}

bool BSTree:: insert(Movie* m) {
    return insert(m, head);
}

bool BSTree:: retrieve(Movie* target, Movie*& item) {
    return retrieve(target, item, head);
}

void BSTree:: clear() {
    clear(head);
}

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

void BSTree:: clear(Node* node) {
    if (node == NULL) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node->pDate;
}

void BSTree:: display() const {
    display(head);
}

void BSTree:: display(Node* node) const {
    if (node == NULL) {
        return;
    }
    display(node->left);
    cout << node->pDate->toString() << endl;
    display(node->right);
}
