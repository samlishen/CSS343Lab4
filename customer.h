
//  customer.h
//  MovieStore
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __MovieStore__customer__
#define __MovieStore__customer__

#include "movie.h"
#include <vector>
#include <string>
using namespace std;

class Instruction;

class Customer {
public:
    Customer();
    Customer(string,string, int);
    virtual ~Customer();
    
    int getID() const;
    string getFirstName() const;
    string getLastName()const;
    
    bool operator == (const Customer&) const;
    void addHistory(Instruction*);
    virtual void displayHistory()const;
    
    bool getOwn(Movie* m,Movie*& save)const;
    bool checkOwn(Movie* m)const;
    bool addOwn(Movie* m);
    bool deleteOwn(Movie* m);
    
    virtual Customer* create(ifstream&) const ;
    
private:
    int ID;
    string first;
    string last;
    
    vector<Instruction*> history;
    vector<Movie*> owned;
};

#endif /* defined(__MovieStore__customer__) */
