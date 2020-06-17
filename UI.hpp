//
//  UI.hpp
//  lab6
//
//  Created by Purdea Razvan on 01/06/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include "Controller.hpp"
#include "Validator.hpp"

class UI{
public:
    Controller controller;
    Validator validator;
    //Admin interface
    void add_movie();
    void del_movie();
    void print_all();
    void modify(int choice, int position);
    //User interface
    void add_to_watchlist();
    void del_from_watchlist();
    void print_watchlist();
    void check_by_genre();
    //Menu interface
    int main_menu();
    int admin_menu();
    int user_menu();
    int modify_menu();
    //helper functions
    bool isnumber(string number);
    void test();
    void press();
    //void inc_likes(Movie movie);
    
};
#endif /* UI_hpp */
