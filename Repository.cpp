//
//  Repository.cpp
//  lab6
//
//  Created by Purdea Razvan on 28/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#include "Repository.hpp"

Repository::Repository(){
    fill_repo();
}
Repository::Repository(vector<Movie> list){
   this->movie_list = list;
}

void Repository::add(Movie new_movie){
    movie_list.push_back(new_movie);
}
void Repository::del(Movie old_movie){
    for(int i=0; i<movie_list.size(); i++){
        if(movie_list[i].get_title() == old_movie.get_title()){
            movie_list.erase(movie_list.begin() +  i);
        }
    }
}
void Repository::del(int pos){
    movie_list.erase(movie_list.begin() + pos);
}
void Repository::set_title(int pos, string new_title){
    movie_list[pos].set_title(new_title);
}
void Repository::set_genre(int pos, string new_genre){
    movie_list[pos].set_genre(new_genre);
}
void Repository::set_year(int pos, int new_year){
    movie_list[pos].set_year(new_year);
}
void Repository::set_likes(int pos, int new_likes){
    movie_list[pos].set_likes(new_likes);
}
void Repository::inc_likes(int pos){
    movie_list[pos].inc_likes();
}
void Repository::set_trailer(int pos, string new_trailer){
    movie_list[pos].set_trailer(new_trailer);
}

void Repository::fill_repo(){
    add(Movie("Avengers", "Action", 2012, 1000, "https://www.youtube.com/watch?v=eOrNdBpGMv8"));
    add(Movie("Captain Marvel", "Action", 2019, 700, "https://www.youtube.com/watch?v=Z1BCujX3pw8"));
    add(Movie("Spider-man", "Action", 2018, 500, "https://www.youtube.com/watch?v=n9DwoQ7HWvI"));
    add(Movie("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=-iRajLSA8TA"));
    add(Movie("Thor", "Comedy", 2011, 300, "https://www.youtube.com/watch?v=JOddp-nlNvQ"));
    add(Movie("Inception", "Drama", 2010, 20000, "https://www.youtube.com/watch?v=F-eMt3SrfFU"));
    add(Movie("The Godfather", "Crime", 1972, 300000, "https://www.youtube.com/watch?v=sY1S34973zA"));
    add(Movie("John Wick", "Crime", 2014, 10000,"https://www.youtube.com/watch?v=2AUmvWm5ZDQ"));
    add(Movie("Shashank redemption", "Drama", 1994, 20000, "https://www.youtube.com/watch?v=6hB3S9bIaco"));
    add(Movie("Deadpool", "Sci-fi", 2016, 200000, "https://www.youtube.com/watch?v=ONHBaC-pfsk"));
}
//////////////////////////////////
void Watchlist::add(Movie new_movie){
    watchlist.push_back(new_movie);
}
void Watchlist::del(Movie old_movie){
    for(int i=0; i<watchlist.size(); i++){
        if(watchlist[i].get_title() == old_movie.get_title()){
            watchlist.erase(watchlist.begin() +  i);
        }
    }
}
void Repository::read_from_file(){
    ifstream file;
    file.open("/Users/purdearazvan/Documents/Anul I/OOP/lab6/lab6/File_Repository.txt");
    if(file.fail()){
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    string title, genre, trailer;
    int year, likes;
    while(file >> title >> genre >> year >> likes >> trailer){
        add(Movie(title, genre, year, likes, trailer));
    }
    file.close();
}

