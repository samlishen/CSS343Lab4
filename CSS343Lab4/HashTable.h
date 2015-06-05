//
//  HashTable.h
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

//
//  hashTable343.h
//  StoreSegment
//
//  Created by Shih Kuo-Ting on 6/4/15.
//  Copyright (c) 2015 Shih Kuo-Ting. All rights reserved.
//

#ifndef __MovieStoreSegment__hashTable__
#define __MovieStoreSegment__hashTable__
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

template < class T>

class HashTable{
public:
    HashTable();
    bool insert( int,T*);
    void display()const;
    int getSize()const;
    bool checkID(int )const;
    bool retrieve(int, T* &)const;
    
    bool remove(int);
    
    
    
    
private:
    int hash(int)const;
    int size;
    int maxsize;
    
    
    struct LinkNode{
        T* data;
        int key;
        LinkNode* next;
        ~LinkNode(){
            delete data;
            
        }
    };
    struct LinkList{
        LinkNode* root;
    };
    
    LinkList* array;
    
};



template<class T>
HashTable<T>::HashTable(){
    size=0;
    maxsize=2;
    array=new LinkList[maxsize];
    
    for(int i=0;i<maxsize;i++){
        
        array[i].root=NULL;
    }
}

template<class T>
bool HashTable<T>::insert(int c, T* data){
    
    if(checkID(c)){
        return false;
    }
    int index=hash(c);
    if(array[index].root==NULL){
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

template<class T>
int HashTable<T>::getSize()const{
    return size;
}

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
template<class T>
int HashTable<T>::hash(int c)const{
    int index;
    
    index=c;
    
    if(index<0)
        index=index*(-1);
    index=index%maxsize;
    
    
    return index;
}template <class T>
bool HashTable<T>::remove(int num){
    if(!checkID(num)){
        return false;
    }
    else{
        int index=hash(num);
        
        LinkNode* curr=array[index].root;
        if(curr->next==NULL){
            delete array[index].root;
            array[index].root=NULL;
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
template <class T>
bool HashTable<T>::retrieve(int num, T* & save)const{
    if(!checkID(num)){
        save=NULL;
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
