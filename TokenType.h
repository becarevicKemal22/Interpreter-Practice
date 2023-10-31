//
// Created by kemal on 30/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_TOKENTYPE_H
#define PROGRAMMING_LANGUAGE_V2_TOKENTYPE_H

enum class TokenType {
    Null,
    Number,
    Identifier,

    Equals,
    OpenParen, CloseParen,
    BinaryOperator,
    Eof,

    Let,
};

#endif //PROGRAMMING_LANGUAGE_V2_TOKENTYPE_H
