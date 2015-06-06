//
//  drama.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "drama.h"

ostream& operator <<(ostream& outStream, const Drama& drama) {
    outStream << drama.toString() << drama.displayType();
    return outStream;
}

Drama:: Drama() : Movie() {
    
}

Drama:: ~Drama() {
    
}

Movie* Drama:: create(ifstream& infile) const {
    Drama* newMovie = new Drama;
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

Movie* Drama:: createSimpleVersion(ifstream& infile) const {
    Drama* newMovie = new Drama;
    string d, t;
    
    infile.get();
    getline(infile, d, ',');
    
    infile.get();
    getline(infile, t, ',');
    
    newMovie->director = d;
    newMovie->title = t;
    
    return newMovie;
}

char Drama:: getType() const {
    return 'D';
}


bool Drama:: operator<(const Movie& movie) const {
    Drama that = static_cast<const Drama&>(movie);
    if (director < that.director) {
        return true;
    }
    if (director == that.director && title < that.title) {
        return true;
    }
    return false;
}

bool Drama:: operator==(const Movie& movie) const {
    Drama that = static_cast<const Drama&>(movie);
    return director == that.director && title == that.title;
}

bool Drama:: operator>(const Movie& movie) const {
    Drama that = static_cast<const Drama&>(movie);
    if (director > that.director) {
        return true;
    }
    if (director == that.director && title > that.title) {
        return true;
    }
    return false;
}