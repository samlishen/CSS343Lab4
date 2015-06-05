//
//  comedy.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "comedy.h"

ostream& operator << (ostream& outStream, const Comedy& comedy) {
    outStream << comedy.toString() << comedy.displayType();
    return outStream;
}

Comedy:: Comedy() : Movie() {
    
}

Comedy:: ~Comedy() {
    
}

Movie* Comedy:: create(ifstream& infile) const {
    Comedy* newMovie = new Comedy;
    string d, t;
    int y;
    
    infile.get();
    getline(infile, d, ',');
    
    infile.get();
    getline(infile, t, ',');
    
    infile.get();
    infile >> y;
    newMovie->director = d;
    newMovie->title = t;
    newMovie->year = y;
    return newMovie;
}

char Comedy:: getType() const {
    return 'F';
}

bool Comedy:: operator<(const Movie& movie) const {
    Comedy that = static_cast<const Comedy&>(movie);
    if (title < that.title) {
        return true;
    }
    if (title == that.title && year < that.year) {
        return true;
    }
    return false;
}

bool Comedy:: operator==(const Movie& movie) const {
    Comedy that = static_cast<const Comedy&>(movie);
    return title == that.title && year == that.year;
}

bool Comedy:: operator>(const Movie& movie) const {
    Comedy that = static_cast<const Comedy&>(movie);
    if (title > that.title) {
        return true;
    }
    if (title == that.title && year > that.year) {
        return true;
    }
    return false;
}