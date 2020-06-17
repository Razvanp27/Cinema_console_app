//
//  Exception.hpp
//  lab6
//
//  Created by Purdea Razvan on 29/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Exception : public exception {
private:
    string msg;
public:
    string get_msg();
    Exception(string msg);
};

#endif /* Exception_hpp */
