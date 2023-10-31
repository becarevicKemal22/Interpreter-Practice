//
// Created by kemal on 30/10/2023.
//

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <unordered_map>
#include "Lexer.h"
#include "Token.h"
#include "TokenType.h"

namespace {
    Token token(std::string value, TokenType type){
        //std::cout << "Token value: " << value << ", Tokentype: " << type << std::endl;
        return {value, type};
    }

    Token token(char value, TokenType type){
        char charArr[2] = {value, '\0'};
        std::string str(charArr);
        return token(str, type);
    }

    char shift(std::vector<char>& src){
        char value = src[0];
        src.erase(src.begin());
        return value;
    }

    bool isSkippable(char ch){
        return ch == ' ' || ch == '\n' || ch == '\t';
    }

    std::unordered_map<std::string, TokenType> KEYWORDS = {
            {"let", TokenType::Let},
            {"null", TokenType::Null},
    };
}

std::vector<Token> tokenize(std::string source){
    std::vector<Token> tokens = {};
    std::vector<char> src;
    for(char c : source) {
        src.push_back(c);
    }

    while(!src.empty()){
        if(src[0] == '('){
            tokens.push_back(token(shift(src), TokenType::OpenParen));
        }else if(src[0] == ')'){
            tokens.push_back(token(shift(src), TokenType::CloseParen));
        }else if(src[0] == '-' || src[0] == '+' || src[0] == '*' || src[0] == '/' || src[0] == '%'){
            tokens.push_back(token(shift(src), TokenType::BinaryOperator));
        }else if(src[0] == '='){
            tokens.push_back(token(shift(src), TokenType::Equals));
        }else{
            // Handle multicharacter tokens
            // Build number token
            if(isdigit(src[0])){
                std::string num = "";
                while(!src.empty() && isdigit(src[0])){
                    num += shift(src);
                }

                tokens.push_back(token(num, TokenType::Number));

            }else if(isalpha(src[0])){
                std::string ident;
                while(!src.empty() && isalpha(src[0])){
                    ident += shift(src);
                }
                TokenType type = TokenType::Identifier;
                if(KEYWORDS.find(ident) != KEYWORDS.end()){
                    type = KEYWORDS[ident];
                }

                tokens.push_back(token(ident, type));

            }else if(isSkippable(src[0])){
                shift(src);
            }else{
                std::cout << "Unrecognized token: " << src[0] << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    tokens.emplace_back("EndOfFile", TokenType::Eof);

    return tokens;
}
