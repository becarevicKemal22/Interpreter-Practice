//
// Created by kemal on 30/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_TOKEN_H
#define PROGRAMMING_LANGUAGE_V2_TOKEN_H

#include <string>
#include "TokenType.h"

class Token {
public:
    Token(std::string value, TokenType type) : value(value), type(type) {}
    std::string value;
    TokenType type;
};

#endif //PROGRAMMING_LANGUAGE_V2_TOKEN_H
