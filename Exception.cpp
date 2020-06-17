//
//  Exception.cpp
//  lab6
//
//  Created by Purdea Razvan on 29/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(string msg){
    this->msg = msg;
}
string Exception::get_msg(){
    return this->msg;
}
