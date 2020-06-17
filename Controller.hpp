//
//  Controller.hpp
//  lab6
//
//  Created by Purdea Razvan on 29/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp
#pragma once
#include <stdio.h>
#include "Repository.hpp"
#include "Validator.hpp"
#include <fstream>

class Controller{
private:
    Repository repo;
    Watchlist watchlist;
public:
    Controller();
    Repository get_repo(){return this->repo;};
    Watchlist get_wl(){return this->watchlist;};
    void print_all_movies(vector<Movie> list);//
    void print_all();
    void del_all();
    bool check_movie(Movie movie, vector<Movie> list);//
    bool isnumber(string nr);//
    int make_int(string str);//
    
    //Admin Mod
    bool add(Movie movie);//
    bool del(string movie);//
    int get_movie_index(string title);//
    //User Mod
    bool add_wl(Movie movie);//
    bool del_wl(string title);//
    void print_watchlist();
    void print_by_genre(string genre, vector<Movie> list);//
    int open_url(Movie movie);//
    int get_wl_index(string title);//
    void save_to_file();//
    void save_wt_to_file();//
    void read_from_file();//
    void read_wt_from_file();//
    //edit functions
    void edit(int choice, int position);//
    void set_title(int pos);//
    void set_genre(int pos);//
    void set_year(int pos);//
    void set_likes(int pos);//
    void set_trailer(int pos);//
    void inc_likes(Movie movie);//
    
    
    
    
    
};

#endif /* Controller_hpp */
