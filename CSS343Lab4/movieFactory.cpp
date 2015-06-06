//
//  movieFactory.cpp
//  CSS343Lab4
//
//  Created by Shen Li on 15/6/4.
//  Copyright (c) 2015年 Shen Li. All rights reserved.
//

#include "movieFactory.h"
#include "classics.h"
#include "drama.h"
#include "comedy.h"

MovieFactory:: MovieFactory() {
    movies = new Movie*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        movies[i] = NULL;
    }
    Movie* classics = new Classics;
    Movie* drama = new Drama;
    Movie* comedy = new Comedy;
    movies[2] = classics;
    movies[3] = drama;
    movies[5] = comedy;
}

MovieFactory:: ~MovieFactory() {
    for (int i = 0; i < SIZE; i++) {
        if (movies[i] != NULL) {
            delete movies[i];
            movies[i] = NULL;
        }
    }
    delete [] movies;
    movies = NULL;
}

Movie* MovieFactory:: createIt(char ch, ifstream& infile) const {
    if (movies[hash(ch)] == NULL) return NULL;
    return movies[hash(ch)]->create(infile);
}

Movie* MovieFactory:: createSimpleIt(char ch, ifstream& infile) const {
    if (movies[hash(ch)] == NULL) return NULL;
    return movies[hash(ch)]->createSimpleVersion(infile);
}

int MovieFactory:: hash(char ch) const {
    return ch - 'A';
}