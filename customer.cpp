//
//  Customer.cpp
//  testCustomer
//
//  Created by Shih Kuo-Ting on 6/4/15.
//  Copyright (c) 2015 Shih Kuo-Ting. All rights reserved.
//


#include "customer.h"
#include <iostream>

using namespace std;
Customer::Customer(){
    first="";
    last="";
    ID=-1;
}

Customer::Customer(string a,string b,int c){
    first=a;
    last=b;
    ID=c;
}

int Customer::getID()const{
    return ID;
    
}
string Customer::getFirstName()const{
    return first;
}

Customer::~Customer(){
    
    
}
bool Customer::addOwn(Movie* m){
    if(checkOwn(m)){
        return false;
    }
    vector<Movie*>::iterator it=owned.begin();
    owned.insert(it,m);
    return true;
}
bool Customer::checkOwn(Movie* m)const{
    for(int i=0;i<owned.size();i++){
        if(*(owned[i])==*m){
            return true;
        }
        
    }
    return false;
}

bool Customer::deleteOwn(Movie* m){
    if(!checkOwn(m)){
        return false;
    }
    vector<Movie*>::iterator it=owned.begin();
    for(int i=0;i<owned.size();i++){
        if(*(owned[i])==*m){
            owned.erase(it);
            return true;
        }
        it++;
    }
    
    return true;
    
}

bool Customer::getOwn(Movie* m,Movie* save)const{
    if(!checkOwn(m)){
        save=NULL;
        return false;
    }
    for(int i=0;i<owned.size();i++){
        if(*(owned[i])==*m){
            save=owned[i];
            return true;
        }
        
    }
    
    return true;
    
}


bool Customer::operator == (const Customer& c) const{
    
    if(ID==c.ID){
        return true;
    }
    return false;
    
}

void Customer::addHistory(Command* com){
    vector<Command*>::iterator it=history.begin();
    history.insert(it,com);
}
void Customer::displayHistory()const{
    
    for(int i=0;i<history.size();i++){
        cout<<history[i]->toString()<<endl;
    }
    
}

Customer* Customer:: create(ifstream& infile) const {
    Customer* newCustomer = new Customer;
    int id;
    string f, l;
    infile >> id;
    infile >> f >> l;
    newCustomer->first = f;
    newCustomer->last = l;
    newCustomer->ID = id;
    return newCustomer;
}




