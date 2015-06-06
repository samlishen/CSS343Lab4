//
//  Customer.cpp
//  testCustomer
//
//  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//


#include "customer.h"
#include "instruction.h"
#include <iostream>

using namespace std;

/**----------------------------------------------------------------------
 customer default constructor
 ----------------------------------------------------------------------*/
Customer::Customer(){
    first="";
    last="";
    ID=-1;
}

/**----------------------------------------------------------------------
 constructor take three parameter and initialize basic data
 
 a= first name
 b= last name
 c= id
 
 ----------------------------------------------------------------------*/
Customer::Customer(string a,string b,int c){
    first=a;
    last=b;
    ID=c;
}
/**----------------------------------------------------------------------
 return ID
 ----------------------------------------------------------------------*/
int Customer::getID()const{
    return ID;
    
}


/**----------------------------------------------------------------------
  return first name
  ----------------------------------------------------------------------*/
string Customer::getFirstName()const{
    return first;
}


/**----------------------------------------------------------------------
 destructor
 ----------------------------------------------------------------------*/
Customer::~Customer(){
    
    
}

/**----------------------------------------------------------------------
 add one movie to customer account
 represent that this movie is holded by customer
 return true if the movie is owned by customer
 return false if not
 ----------------------------------------------------------------------*/
bool Customer::addOwn(Movie* m){
    if(checkOwn(m)){
        return false;
    }
    vector<Movie*>::iterator it=owned.begin();
    owned.insert(it,m);
    return true;
}

/**----------------------------------------------------------------------
 check the customer own specific movie or not
 return true if the movie is owned by customer
 return false if not
 ----------------------------------------------------------------------*/
bool Customer::checkOwn(Movie* m)const{
    for(int i=0;i<owned.size();i++){
        if(*(owned[i])==*m){
            return true;
        }
        
    }
    return false;
}


/**----------------------------------------------------------------------
 delete specific movie owned by customer
 call when someone return movie
 return true if the movie is owned by customer
 return false if not
 ----------------------------------------------------------------------*/
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


/**----------------------------------------------------------------------
 get info for specific movie own by customer
 return true if the movie is owned by customer
 return false if not
 ----------------------------------------------------------------------*/
bool Customer::getOwn(Movie* m,Movie*& save)const{
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


/**----------------------------------------------------------------------
  compare two customer based on ID
 ----------------------------------------------------------------------*/

bool Customer::operator == (const Customer& c) const{
    
    if(ID==c.ID){
        return true;
    }
    return false;
    
}


/**----------------------------------------------------------------------
 add specific instruction object to customer's history profile
 ----------------------------------------------------------------------*/
void Customer::addHistory(Instruction* com){
    vector<Instruction*>::iterator it=history.begin();
    history.insert(it,com);
}


/**----------------------------------------------------------------------
 show customer history
 ----------------------------------------------------------------------*/
void Customer::displayHistory()const{
    cout << "Here is the history for: "
    << first << " " << last << " " << ID << endl;
    for(int i=history.size()-1;i>=0;i--){
        cout<<"\t"<<history[i]->toString()<<endl;
    }
    
}


/**----------------------------------------------------------------------
 create method used by factory
 ----------------------------------------------------------------------*/

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




