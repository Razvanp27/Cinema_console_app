//
//  Controller.cpp
//  lab6
//
//  Created by Purdea Razvan on 29/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//
#include "Controller.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

Controller::Controller(){
    read_from_file();
}
bool Controller::isnumber(string str){
    if(str.size()==0) return false;
    for(int i=0;i<str.size();i++) {
        if((str[i]>='0' && str[i]<='9')==false) {
            return false;
        }
    }
    return true;
}
int Controller::make_int(string str)
{
    int ret=0;
    for(int i=0;i<str.length();i++)
    {
        ret=ret*10+(str[i]-48);
    }
    return ret;
}
void Controller::print_all_movies(vector<Movie> list){
    for(int i=0; i< list.size(); i++){
        cout<<i+1<<", ";
        list[i].get_str();
    }
}
void Controller::print_all(){
    if(get_repo().movie_list.size() == 0){
        cout<<"None"<<endl;
        return;
    }
    print_all_movies(get_repo().movie_list);
}
bool Controller::check_movie(Movie movie, vector<Movie> list){
    for(int i=0; i< list.size(); i++){
        if(list[i].get_title() == movie.get_title()){
            return false;
        }
    }
    return true;
}
bool Controller::add(Movie movie){
    if(!check_movie(movie, repo.movie_list)){
        cout<<"Movie already in list."<<endl;
        return false;
    }
    else{
        repo.add(movie);
        return true;
    }
}
bool Controller::del(string movie){
    int pos = get_movie_index(movie);
    if(pos == -1){
        return false;
    }
    else{
        repo.del(pos);
        return true;
    }
}
int Controller::get_movie_index(string title){
    for(int index = 0; index < repo.movie_list.size(); index++){
        if(repo.movie_list[index].get_title() == title){
            return index;
        }
    }
    return -1;
}
int Controller::open_url(Movie movie){
    string url = movie.get_trailer();
    cout << url << endl;
    string op = string("open ").append(url);
    system(op.c_str());
    return 0;
}
bool Controller::add_wl(Movie movie){
    if(!check_movie(movie, watchlist.watchlist)){
        cout<<"Movie already in list."<<endl;
        return false;
    }
    else{
        watchlist.add(movie);
        return true;
    }
}
bool Controller::del_wl(string title){
    int choice;
    int index = get_movie_index(title);
    int wl_index = get_wl_index(title);
    if(index == -1){
        cout<<"Movie not in list."<<endl;
        return false;
    }
    else{
    watchlist.watchlist.erase(watchlist.watchlist.begin() + wl_index);
        cout<<"Press 1 to like this movie or 0 to exit."<<endl;
        cin>>choice;
        if(choice == 1){
            repo.movie_list[index].inc_likes();
    }
    return true;
}
}
int Controller::get_wl_index(string title){
    for(int index = 0; index < watchlist.watchlist.size(); index++){
        if(watchlist.watchlist[index].get_title() == title){
            return index;
        }
    }
    return -1;
}
void Controller::print_by_genre(string genre, vector<Movie> list){
    bool open = true;
    int y = 1;
    if(list.size() == 0){cout<<"None"<<endl;return;};
    while(open != false){
        for(int i=0; i<list.size(); i++){
            if(genre == "\n"){
                cout<<i+1<<". ";list[i].get_str();
            }
        }
        for(int i=0; i<list.size(); i++){
            if(list[i].get_genre() == genre){
                cout<<y<<". ";list[i].get_str();
                y++;
            }
        }
        int choice=-1, choice2=-1;
        cout<<"If you want to check the trailer of a specific movie, select it or press 0 to exit: ";
        cin>>choice;
        if(choice > 0){
            open_url(list[choice-1]);
            cin.ignore();
            cout<<"Do you want to add this movie to your wishlist? If yes, press 1 or 0 to exit: ";
            cin>>choice2;
            if(choice2 == 1){
                watchlist.add(list[choice-1]);
            }}
        else{
            open = false;
            return;
        }
    }
    }
void Controller::save_to_file(){
    ofstream file;
    file.open("/Users/purdearazvan/Documents/Anul I/OOP/lab6/lab6/File_Repository.txt");
    if(file.fail()){
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    for(int i=0; i<repo.movie_list.size(); i++){
        file<<repo.movie_list[i].get_title()<<" "<<repo.movie_list[i].get_genre()<<" "<<repo.movie_list[i].get_year()<<" "<<repo.movie_list[i].get_likes()<<" "<<repo.movie_list[i].get_trailer()<<endl;
    }
    file.close();
}
void Controller::read_from_file(){
    ifstream file;
    file.open("/Users/purdearazvan/Documents/Anul I/OOP/lab6/lab6/File_Repository.txt");
    if(file.fail()){
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    string title, genre, trailer, line;
    int year, likes;
    
    while(getline(file, line)){
        istringstream iss(line);
        if(!(iss>>title>>genre>>year>>likes>>trailer)){break;};
        add(Movie(title, genre, year, likes, trailer));
        /*
    while(file >> title >> genre >> year >> likes >> trailer){
        add(Movie(title, genre, year, likes, trailer));*/
    }
    file.close();
}


void Controller::edit(int choice, int position){
    int pos = position;
    string title, new_title;
    if(choice == 1){
        set_title(pos);
    }
    if(choice == 2){
        set_genre(pos);
    }
    if(choice == 3){
        set_year(pos);
    }
    if(choice == 4){
        set_likes(pos);
    }
    if(choice == 5){
        set_trailer(pos);
    }
    repo.movie_list[pos].get_str();
}
void Controller::set_title(int pos){
    string title, new_title;
    cout<<"Please enter the new title: ";
    cin>>title;
    repo.movie_list[pos].set_title(title);
}
void Controller::set_genre(int pos){
    string genre, new_genre;
    cout<<"Please enter the new genre: ";
    cin>>genre;
    repo.movie_list[pos].set_genre(new_genre);
}
void Controller::set_year(int pos){
    int year = -1;
    bool check = false;
    while(!check){
        cout<<"Please enter the new year: ";
        cin>>year;
        if(year > 1920 and year < 2020){
            check = true;
        }
    }
    repo.movie_list[pos].set_year(year);
}
void Controller::set_likes(int pos){
    int likes = -1;
    bool check = false;
    while(!check){
        cout<<"Please enter the new likes: ";
        cin>>likes;
        if(likes > 0){
            check = true;
        }
    }
    repo.movie_list[pos].set_likes(likes);
}
void Controller::set_trailer(int pos){
    string trailer;
    cout<<"Please enter the new trailer link: ";
    cin>>trailer;
    repo.movie_list[pos].set_trailer(trailer);
}
void Controller::inc_likes(Movie movie){
    for(int i=0; i<repo.movie_list.size(); i++){
        if(repo.movie_list[i].get_title() == movie.get_title()){
            repo.movie_list[i].inc_likes();
        }
    }
}
void Controller::del_all(){
    if(repo.movie_list.size() == 0){
        cout<<"None."<<endl;
        return;
    }
    for(int i=0; i<repo.movie_list.size(); i++){
        repo.del(i);
    }
    cout<<repo.movie_list.size()<<endl;
}

void Controller::save_wt_to_file(){
    ofstream file;
    file.open("/Users/purdearazvan/Documents/Anul I/OOP/lab6/lab6/File_Watchlist.txt");
    if(file.fail()){
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    for(int i=0; i<watchlist.watchlist.size(); i++){
        file<<watchlist.watchlist[i].get_title()<<" "<<watchlist.watchlist[i].get_genre()<<" "<<watchlist.watchlist[i].get_year()<<" "<<watchlist.watchlist[i].get_likes()<<" "<<watchlist.watchlist[i].get_trailer()<<endl;
    }
    file.close();
}
void Controller::read_wt_from_file(){
    ifstream file;
    file.open("/Users/purdearazvan/Documents/Anul I/OOP/lab6/lab6/File_Watchlist.txt");
    if(file.fail()){
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    string title, genre, trailer;
    int year, likes;
    while(file >> title >> genre >> year >> likes >> trailer){
        add_wl(Movie(title, genre, year, likes, trailer));
    }
    file.close();
}
void Controller::print_watchlist(){
    if(watchlist.watchlist.size() == 0){
        cout<<"None."<<endl;
        return;
    }
    else{
        for(int i=0; i<watchlist.watchlist.size(); i++){
            cout<<i+1<<", ";watchlist.watchlist[i].get_str();
        }
    }
}
