//
//hashTable.h
// This hash table hold all kinds of data.
// but duplicate element is not allowed.
///  Created by Shen Li and Kuo on 15/6/4.
//  Copyright (c) 2015年 Shen Li and Kuo All rights reserved.
//

#ifndef __MovieStoreSegment__hashTable__
#define __MovieStoreSegment__hashTable__
#include <vector>

#include <iostream>

using namespace std;

template < class T>

class HashTable{
public:
    HashTable();    //default constructor
    ~HashTable(); //destructor
    bool insert( int,T&);   //insert an object to the table
    void display()const;    //display all the content inside the table
    int getSize()const; //return current size in the hashtable
    bool checkID(int )const;//check existent based on ID
    bool retrieve(int, T&)const;//retrieve object based on ID
    
    bool remove(int);//remove object based on ID
    
    
    
    
private:
    int hash(int)const;//hash function
    int size;//current size
    int maxsize;//this is the size of the array. But users can input as many
    //data as they want.
    
    
    //node for the linklist
    struct LinkNode{
        T data;
        int key;
        LinkNode* next;
        ~LinkNode(){
            
            
        }
    };
    
    //linklist object hold by array
    struct LinkList{
        LinkNode* root;
    };
    
    //this is an array of LinkList object
    LinkList* array;
    
};

/**----------------------------------------------------------------------
 Below is the actual code for Hashtable.
 
 In order to let hashtable to hold all kinds of data, I use template to
 implement it. But we can only code in .h file due to using template. We
 try to implement the actual code in .cpp file but we cannot find a way
 to do so. We read your previous code in both 342 and 343 on course
 website. We found that you put the code in .h file when you used template.
 So we do in the same way.
 
 Below is the actual code for Hashtable
 ----------------------------------------------------------------------*/

/**----------------------------------------------------------------------
 destructor
 ----------------------------------------------------------------------*/
template<class T>
HashTable<T>::~HashTable<T>(){}

/**----------------------------------------------------------------------
 constructor
 Initialize the array, and set all linklist root to null
 Although the maxsize is set to 100, it is the size for the array of linklist.
 Users can input unlimit data to this. Set to 100 to lower collision rate.
 
 ----------------------------------------------------------------------*/
template<class T>
HashTable<T>::HashTable(){
    size=0;
    maxsize=100;
    array=new LinkList[maxsize];
    
    for(int i=0;i<maxsize;i++){
        
        array[i].root=NULL;
    }
}

/**----------------------------------------------------------------------
 Insert function
 Insert data to the hashtable based on int.
 Check the int key first, if the key already existed in the hashtable,
 the function return false and do nothing in order to prevent duplicate.
 If the key does not exist, store the data to proper location based on
 the indext return by hash function.
 
 ----------------------------------------------------------------------*/
template<class T>
bool HashTable<T>::insert(int c, T& data){
    
    if(checkID(c)){
        return false;
    }
    
    int index=hash(c);
    
    if(array[index].root==NULL){
        
        //if the linklist in that position has not been intialized, initialize
        //first.
        
        LinkNode* newroot=new LinkNode();
        newroot->next=NULL;
        newroot->key=c;
        newroot->data=data;
        size++;
        array[index].root=newroot;
        return true;
    }
    else{
        LinkNode* curr=array[index].root;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        LinkNode* newnode=new LinkNode();
        newnode->next=NULL;
        newnode->data=data;
        newnode->key=c;
        size++;
        curr->next=newnode;
        return true;
        
    }
    return false;
    
}

/**----------------------------------------------------------------------
 return  the current number of data
 ----------------------------------------------------------------------*/
template<class T>
int HashTable<T>::getSize()const{
    return size;
}


/**----------------------------------------------------------------------
 print all data based on the order in array.
 ----------------------------------------------------------------------*/
template<class T>
void HashTable<T>::display()const{
    
    for(int i=0;i<maxsize;i++){
        cout<<i<<"\t";
        
        if(array[i].root==NULL){
            cout<<"NULL";
        }
        else{
            LinkNode* curr=array[i].root;
            while(curr!=NULL){
                cout<<curr->key<<"\t";
                cout<<*(curr->data)<<"\t";
                curr=curr->next;
            }
        }
        cout<<endl;
    }
}


/**----------------------------------------------------------------------
 Check if data exist based on its key, which is an int
 It will hash the int and get the indext first.
 If can't find the key, return false
 ----------------------------------------------------------------------*/
template<class T>
bool HashTable<T>::checkID(int num)const{
    int index=hash(num);
    
    if(array[index].root==NULL){
        return false;
    }
    else{
        LinkNode* curr=array[index].root;
        while(curr!=NULL){
            if(curr->key==num){
                return true;
            }
            curr=curr->next;
        }
    }
    return false;
    
}


/**----------------------------------------------------------------------
 Hash function for integer
 take all kinds of integer
 will get the absolute value if input is negative
 ----------------------------------------------------------------------*/
template<class T>
int HashTable<T>::hash(int c)const{
    int index;
    
    index=c;
    
    if(index<0)
        index=index*(-1);
    index=index%maxsize;
    
    
    return index;
}

/**----------------------------------------------------------------------
 remove function
 remove specific data based on its key
 pass the key to hash function first and get its indext
 if the input key cannot be found, then the data does not exist and return
 false.
 if the key can be found, remove and delete that data from hashtable.
 
 ----------------------------------------------------------------------*/
template <class T>
bool HashTable<T>::remove(int num){
    if(!checkID(num)){
        return false;
    }
    else{
        int index=hash(num);
        size--;
        LinkNode* curr=array[index].root;
        
        if(curr->next==NULL){
            delete array[index].root;
            array[index].root=NULL;
            return true;
        }
        if(curr->key==num){
            
            array[index].root=curr->next;
            delete curr;
            return true;
        }
        else{
            while(curr->next!=NULL){
                if(curr->next->key==num){
                    LinkNode* nextnext=curr->next;
                    curr->next=curr->next->next;
                    nextnext->next=NULL;
                    delete nextnext;
                    
                    return true;
                }
                curr=curr->next;
                
            }
            return true;
        }
        return true;
    }
}

/**----------------------------------------------------------------------
 retrieve function
 Get specific data based on key
 Take two parameter, one int which is key, one data object, which is used
 to store the data.
 If the key can be found, the data exist and save the data in the "save"
 parameter. return true
 If the key cannot be found, return false and do nothing.
 ----------------------------------------------------------------------*/
template <class T>
bool HashTable<T>::retrieve(int num, T& save)const{
    if(!checkID(num)){
        
        return false;
    }
    else{
        int index=hash(num);
        LinkNode* curr=array[index].root;
        
        while(curr!=NULL){
            if(curr->key==num){
                save=curr->data;
                
                return true;
            }
            curr=curr->next;
        }
        return false;
    }
}
#endif
