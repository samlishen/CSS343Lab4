//
//  classics.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "classics.h"

ostream& operator <<(ostream& outStream, const Classics& classics) {
    outStream << classics.toString() << classics.displayType();
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

Movie* Classics:: createSimpleVersion(ifstream& infile) const {
    Classics* newMovie = new Classics;
    int m, y;
    string f, l;
    
    infile.get();
    infile >> m >> y;
    
    infile.get();
    infile >> f >> l;
    
    newMovie->month = m;
    newMovie->year = y;
    newMovie->actorFirstName = f;
    newMovie->actorLastName = l;
    
    return newMovie;
}

char Classics:: getType() const {
    return 'C';
}

string Classics:: toString() const {
    string retVal = title + "\t\t\t" + director + "\t\t" + to_string(year) +
    "." + to_string(month) + "\t" + actorFirstName + " " + actorLastName;
    return retVal;
}


bool Classics:: operator < (const Movie& movie) const {
    Classics that = static_cast<const Classics&>(movie);
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

bool Classics:: operator==(const Movie& movie) const {
    Classics that = static_cast<const Classics&>(movie);
    return year == that.year &&
    month == that.month &&
    actorFirstName == that.actorFirstName &&
    actorLastName == that.actorLastName;
}

bool Classics:: operator>(const Movie& movie) const {
    Classics that = static_cast<const Classics&>(movie);
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