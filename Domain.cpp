//
//  Domain.cpp
//  lab6
//
//  Created by Purdea Razvan on 28/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#include "Domain.hpp"

Movie::Movie(){
    this->title = '0';
    this->genre = '0';
    this->year = 0;
    this->likes = 0;
    this->trailer  = '0';
}
//constructor
Movie::Movie(string title, string genre, int year, int likes, string trailer){
    this->title = title;
    this->genre = genre;
    this->year = year;
    this->likes = likes;
    this->trailer = trailer;
}
//getters
string Movie::get_title(){return this->title;};
string Movie::get_genre(){return this->genre;};
int Movie::get_year(){return this->year;};
int Movie::get_likes(){return this->likes;};
string Movie::get_trailer(){return this->trailer;};
void Movie::get_str(){
    cout<<"Title:"<<title<<", genre:"<<genre<<", year:"<<year<<", likes:"<<likes<<", trailer:"<<trailer<<endl;
}
//setters
void Movie::set_title(string new_title){this->title = new_title;};
void Movie::set_genre(string new_genre){this->genre = new_genre;};
void Movie::set_year(int new_year){this->year = new_year;};
void Movie::inc_likes(){this->likes++;};
void Movie::set_likes(int new_likes){this->likes = new_likes;};
void Movie::set_trailer(string new_trailer){this->trailer = new_trailer;};


