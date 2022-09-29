//
// Created by breno on 22/09/2022.
//

#ifndef PROJETO2_MOVIE_H
#define PROJETO2_MOVIE_H

#include <iostream>

using namespace std;

class Movie {
public:
    string show_id;
    string type;
    string title;
    string director;
    string cast;
    string country;
    string date_added;
    string release_year;
    string rating;
    string duration;
    string listed_in;
    string description;

    virtual ~Movie();
};


#endif //PROJETO2_MOVIE_H
