//
//  Validator.cpp
//  lab6
//
//  Created by Purdea Razvan on 28/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#include "Validator.hpp"


Validator::Validator(){
    cout<<"Validator created."<<endl;
}
void Validator::validate_movie(Movie movie){
    validate_trailer(movie.get_title());
    validate_genre(movie.get_genre());
    validate_year(movie.get_year());
    validate_likes(movie.get_likes());
    validate_trailer(movie.get_trailer());
}
void Validator::validate_index(int pos, int size){
    if(pos < 0){
        throw Exception("Position must be positive.\n)");
    }
    if(pos > size){
        throw Exception("Index out of range.\n");
    }
}
void Validator::validate_title(string title){
    if(title == ""){
        throw Exception("Invalid title.\n");
    }
}

void Validator::validate_genre(string genre){
    if(genre == ""){
        throw Exception("Invalid genre.\n");
    }
}
void Validator::validate_year(int year){
    if(year < 1900 or year > 2020){
        throw Exception("Invalid year input.\n");
    }
}
void Validator::validate_likes(int likes){
    if(likes < 0){
        throw Exception("Invalid likes, input must be positive.\n");
    }
}
void Validator::validate_trailer(string trailer){
    if (trailer == ""){
        throw Exception("Invalid trailer link.\n");
    }
}

