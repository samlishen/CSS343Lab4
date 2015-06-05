//
//  classics.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "classics.h"

ostream& operator <<(ostream& outStream, const Classics& classics) {
    outStream
    << classics.title << "\t\t"
    << classics.director << "\t"
    << classics.year << "." << classics.month << "\t"
    << classics.actorFirstName << " " << classics.actorLastName
    << endl;
    for (int i = 0; i < 26; i++) {
        if (classics.type[i] != NULL) {
            outStream << classics.type[i]->getTypeName()
            << ":\t" << classics.type[i]->getCurrent() << "/"
            << classics.type[i]->getMax() << endl;
        }
    }
    return outStream;
}

Classics:: Classics() : Movie(){
    
}

Classics:: ~Classics(){
    
}

Movie* Classics:: create(ifstream& infile) const {
    Classics* newMovie = new Classics;
    string d, t, f, l;
    int m, y;
    
    infile.get();
    getline(infile, d, ',');
    
    infile.get();
    getline(infile, t, ',');
    
    infile.get();
    infile >> f >> l;
    infile >> m >> y;
    
    newMovie->director = d;
    newMovie->title = t;
    newMovie->actorFirstName = f;
    newMovie->actorLastName = l;
    newMovie->month = m;
    newMovie->year = y;
    
    return newMovie;
}

bool Classics:: operator < (const Classics& that) const {
    if (year < that.year) {
        return true;
    }
    if (year == that.year && month < that.month) {
        return true;
    }
    if (year == that.year && month == that.month &&
        actorFirstName < that.actorFirstName) {
        return true;
    }
    if (year == that.year && month == that.month &&
        actorFirstName == that.actorFirstName &&
        actorLastName < that.actorLastName) {
        return true;
    }
    return false;
}

bool Classics:: operator==(const Classics& that) const {
    return year == that.year &&
    month == that.month &&
    actorFirstName == that.actorFirstName &&
    actorLastName == that.actorLastName;
}

bool Classics:: operator>(const Classics& that) const {
    if (year > that.year) {
        return true;
    }
    if (year == that.year && month > that.month) {
        return true;
    }
    if (year == that.year && month == that.month &&
        actorFirstName > that.actorFirstName) {
        return true;
    }
    if (year == that.year && month == that.month &&
        actorFirstName == that.actorFirstName &&
        actorLastName > that.actorLastName) {
        return true;
    }
    return false;
}