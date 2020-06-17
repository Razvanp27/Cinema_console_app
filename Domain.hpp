//
//  Domain.hpp
//  lab6
//
//  Created by Purdea Razvan on 28/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#ifndef Domain_hpp
#define Domain_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Movie{
private:
    string title;
    string genre;
    int year;
    int likes;
    string trailer;
public:
    //Constructor
    Movie();
    Movie(string title, string genre, int year, int likes, string trailer);
    //getters
    string get_title();
    string get_genre();
    int get_year();
    int get_likes();
    string get_trailer();
    void get_str();
    //setters
    void set_title(string new_title);
    void set_genre(string new_genre);
    void set_year(int new_year);
    void inc_likes();
    void set_likes(int new_likes);
    void set_trailer(string new_trailer);
};
#endif /* Domain_hpp */
