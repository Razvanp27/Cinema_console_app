//
//  Validator.hpp
//  lab6
//
//  Created by Purdea Razvan on 28/05/2019.
//  Copyright © 2019 Purdea Razvan. All rights reserved.
//

#ifndef Validator_hpp
#define Validator_hpp
#pragma once
#include <stdio.h>
#include "Domain.hpp"
#include "Exception.hpp"

class Validator{
private:
    
public:
    Validator();
    void validate_movie(Movie movie);
    void validate_title(string title);
    void validate_genre(string genre);
    void validate_year(int year);
    void validate_likes(int likes);
    void validate_trailer(string trailer);
    void validate_index(int pos, int size);
};


#endif /* Validator_hpp */
