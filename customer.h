
//  customer.h
//  MovieStore
//
//  Created by Shen Li on 15/5/31.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#ifndef __MovieStore__customer__
#define __MovieStore__customer__

#include "movie.h"
#include "command.h"
#include <vector>
#include <string>
using namespace std;

class Customer {
public:
    Customer();
    Customer(string,string, int);
    virtual ~Customer();
    
    int getID() const;
    string getFirstName() const;
    string getLastName()const;
    
    bool operator == (const Customer&) const;
    void addHistory(Command*);
    virtual void displayHistory()const;
    
    bool getOwn(Movie* m,Movie* save)const;
    bool checkOwn(Movie* m)const;
    bool addOwn(Movie* m);
    bool deleteOwn(Movie* m);
    
    
    virtual Customer* create(ifstream&) const ;
    
private:
    int ID;
    string first;
    string last;
    
    vector<Command*> history;
    vector<Movie*> owned;
};

#endif /* defined(__MovieStore__customer__) */
