//
//  UI.cpp
//  lab6
//
//  Created by Purdea Razvan on 01/06/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#include "UI.hpp"
#include <sstream>
#include <string>
#include <exception>
//Admin Interface
void UI::add_movie(){
    string title = "\n", genre = "\n", trailer = "\n";
    int year =-1, likes =-1;
    while(title == "\n"){
        cout<<"Please enter the title of the new film: ";
        cin>>title;
        validator.validate_title(title);}
    while(genre == "\n"){
        cout<<"Please enter the genre of the new film: ";
        cin>>genre;
        validator.validate_genre(genre);}
    while(year==-1){
        cout<<"Please enter the year of the new film: ";
        cin>>year;
        validator.validate_year(year);}
    while(likes==-1){
        cout<<"Please enter the number of likes the new film already have: ";
        cin>>likes;
        validator.validate_likes(likes);}
    while(trailer=="\n"){
        cout<<"Please enter the trailer link to the new film's trailer: ";
        cin>>trailer;
        validator.validate_trailer(trailer);}
    controller.add(Movie(title, genre, year, likes, trailer));
}

void UI::del_movie(){
    string title = "\n";
    while(title == "\n"){
        cout<<"Please enter the title of the movie you want to remove from the list: ";
        cin>>title;
        validator.validate_title(title);}
    controller.del(title);
}
void UI::print_all(){
    controller.print_all();
}
void UI::modify(int choice, int position){
    controller.edit(choice, position);
}

//User interface

void UI::add_to_watchlist(){
    int choice;
    if(controller.get_repo().movie_list.size() == 0){
        cout<<"No movies in list."<<endl;
        return;
    }else{
        for(int i=0; i<controller.get_repo().movie_list.size(); i++){
            cout<<i+1<<". ";
            controller.get_repo().movie_list[i].get_str();
        }
        cout<<"Please select the movie you want to add to your watchlist: ";
        cin>>choice;
        if(choice<0){
            cout<<"Invalid input, please try again."<<endl;
        }
        else{
            controller.add_wl(controller.get_repo().movie_list[choice-1]);
            cout<<"Movies added to the watchlist."<<endl;
        }
    }
}
void UI::del_from_watchlist(){
    int liked, choice2;
    string choice = "0";
    string tmp, ch, title;
    for(int i=0; i<controller.get_wl().watchlist.size(); i++){
        cout<<i+1<<". ";controller.get_wl().watchlist[i].get_str();
    }
    do{
        cout<<"Please select a movie from your watchlist which you want to remove: ";
        cin>>choice;
    }while(!isnumber(choice));
    istringstream iss(choice);
    iss >> choice2;
    title = controller.get_wl().watchlist[choice2-1].get_title();
    cout<<"Press 1 to like this movie, or press 0 to exit: ";
    cin>>liked;
    if(liked == 1){
        for(int i=0; i<controller.get_repo().movie_list.size(); i++){
            if(controller.get_repo().movie_list[i].get_title() == title){
                controller.get_repo().movie_list[i].inc_likes();
            }
        }
    }
    controller.del_wl(title);
    return;
}
void UI::print_watchlist(){
    cout<<"Current movies in the watchlist: "<<endl;
    controller.print_watchlist();
}
void UI::check_by_genre(){
    bool aux = false;
    string genre, new_genre;
    char c;
    while(!aux){
        cin.ignore();
        cout<<"Please enter the genre you want to look for:";
        cin.get(c);
        if(c == '\n')
        {new_genre = "0";
            aux = true;}
        else
        {   cin>>genre;
            reverse(genre.begin(), genre.end());
            genre += c;
            reverse(genre.begin(), genre.end());
            cout<<genre<<endl;
            validator.validate_genre(genre);
            if(genre != ""){aux = true;}
        }
    }
    controller.print_by_genre(genre, controller.get_repo().movie_list);
}


//Menu interface
int UI::main_menu(){
    int choice;
    bool menuOn = true;
    while(menuOn != false){
        cout<<endl
        <<"Please select the admin or user mode: \n"
        <<"1.Admin\n"
        <<"2.User\n"
        <<"3.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                admin_menu();
                break;
            case 2:
                user_menu();
                break;
            case 3:
                cout<<"End of Program.\n";
                menuOn = false;
                break;
            default:
                cout<<"Not a valid Choice. Choose again. \n";
                cin>>choice;
                break;
        }
    }
    return 0;
}
int UI::admin_menu(){
    int choice;
    bool menuOn = true;
    while(menuOn != false){
        cout<<"---Admin Menu---"<<endl
        <<"1. Add a movie.\n"
        <<"2. Delete a movie.\n"
        <<"3. Modify a movie already in list.\n"
        <<"4. Print all movies in list.\n"
        <<"5. Back.\n"
        <<"Please select an option from the Menu: \n";
        cin>>choice;
        switch(choice){
            case 1:
                add_movie();
                press();
                break;
            case 2:
                del_movie();
                press();
                break;
            case 3:
                modify_menu();
                press();
                break;
            case 4:
                print_all();
                press();
                break;
            case 5:
                cout<<"Return to main menu.\n";
                menuOn = false;
                break;
            default:
                cout<<"Not a valid Choice. \n"<<"Choose again. \n";
                cin>>choice;
                break;
        }
    }
    return 0;
}

int UI::user_menu(){
    int choice;
    bool menuOn = true;
    while(menuOn != false){
        cout<<"---User Menu---"<<endl
        <<"1. Add a movie to your watchlist.\n"
        <<"2. Delete a movie from your watchlist.\n"
        <<"3. Print the movies by its genre.\n"
        <<"4. Print all movies in your watchlist.\n"
        <<"5. Print all movies in the list.\n"
        <<"6. Back.\n"
        <<"Please select an option from the Menu: \n";
        cin>>choice;
        switch(choice){
            case 1:
                add_to_watchlist();
                press();
                break;
            case 2:
                del_from_watchlist();
                press();
                break;
            case 3:
                check_by_genre();
                press();
                break;
            case 4:
                print_watchlist();
                press();
                break;
            case 5:
                print_all();
                press();
                break;
            case 6:
                cout<<"Return to main menu.\n";
                menuOn = false;
                break;
            default:
                cout<<"Not a valid Choice. \n"<<"Choose again. \n";
                cin>>choice;
                break;
        }
    }
    return 0;
}
int UI::modify_menu(){
    int choice, number;
    string t,title;
    Movie tmp;
    bool menuOn = true;
    cout<<"---Modify a movie---"<<endl;
    for(int i=0; i<controller.get_repo().movie_list.size(); i++){
        cout<<i+1<<". ";controller.get_repo().movie_list[i].get_str();
    }
    cout<<"Please select the movie you want to modify: ";
    cin>>number;
    number--;
    while(menuOn != false){
        cout<<endl
        <<"1. Change the title of the movie.\n"
        <<"2. Change the genre of the movie.\n"
        <<"3. Change the year of the movie.\n"
        <<"4. Change the number of likes from the movie.\n"
        <<"5. Change the trailer link from the movie.\n"
        <<"6. Back.\n"
        <<"Please select an option from the Menu: \n";
        cin>>choice;
        switch(choice){
            case 1:
                modify(choice, number);
                press();
                break;
            case 2:
                modify(choice, number);
                press();
                break;
            case 3:
                modify(choice, number);
                press();
                break;
            case 4:
                modify(choice, number);
                press();
                break;
            case 5:
                modify(choice, number);
                press();
                break;
            case 6:
                cout<<"Return to admin menu.\n";
                menuOn = false;
                break;
            default:
                cout<<"Not a valid Choice. \n"<<"Choose again. \n";
                cin>>choice;
                break;
        }
    }
    return 0;
}
//Helper functions

bool UI::isnumber(string number){
    if(number.size()==0) return false;
    for(int i=0;i<number.size();i++) {
        if((number[i]>='0' && number[i]<='9')==false) {
            return false;
        }
    }
    return true;

}
void UI::press(){
    cin.ignore();
    cout<<"Press Enter to continue...";
    cin.get();
}

void UI::test(){
    controller.read_from_file();
    //controller.get_repo().fill_repo();
}
