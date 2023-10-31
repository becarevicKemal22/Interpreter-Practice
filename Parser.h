//
// Created by kemal on 31/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_PARSER_H
#define PROGRAMMING_LANGUAGE_V2_PARSER_H

#include <vector>
#include <string>
#include <memory>
#include "Token.h"
#include "Ast.h"

class Parser {
public:
    ast::Program produceAST(std::string sourceCode);
    std::shared_ptr<ast::Stmt> parse_stmt();
    std::shared_ptr<ast::Expr> parse_expr();
    std::shared_ptr<ast::Expr> parse_additive_expr();
    std::shared_ptr<ast::Expr> parse_multiplicative_expr();
    std::shared_ptr<ast::Expr> parse_primary_expr();
private:
    std::vector<Token> tokens = {};
    bool not_eof(){
        return tokens[0].type != TokenType::Eof;
    }
    Token at(){
        return tokens[0];
    }
    Token eat(){
        Token prev = at();
        tokens.erase(tokens.begin());
        return prev;
    }
    Token expect(TokenType type, std::string err);
};


#endif //PROGRAMMING_LANGUAGE_V2_PARSER_H
