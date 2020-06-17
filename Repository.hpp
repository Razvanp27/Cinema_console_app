//
//  Repository.hpp
//  lab6
//
//  Created by Purdea Razvan on 28/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp
#pragma once
#include "Domain.hpp"

class Repository{
private:
  
public:
    vector<Movie> movie_list;
    Repository();
    Repository(vector<Movie> list);
    void fill_repo();
    void read_from_file();
    void add(Movie new_movie);
    void set_title(int pos, string new_name);
    void set_genre(int pos, string new_genre);
    void set_year(int pos, int new_year);
    void set_likes(int pos, int new_likes);
    void inc_likes(int pos);
    void set_trailer(int pos, string new_trailer);
    void del(Movie old_movie);
    void del(int pos);
};
class Watchlist {
private:
    
public:
    vector<Movie> watchlist;
    void add(Movie new_Movie);
    void del(Movie old_movie);
};



#endif /* Repository_hpp */
