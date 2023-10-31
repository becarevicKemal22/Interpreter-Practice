//
// Created by kemal on 31/10/2023.
//

#include <memory>
#include <iostream>
#include "Parser.h"
#include "Lexer.h"
#include "Ast.h"
#include "TokenType.h"

using ast::ExprPtr;

Token Parser::expect(TokenType type, std::string err) {
    Token prev = eat();
    if(prev.type != type){
        std::cout << "Parser error: \n" << err << "\n";
        exit(1);
    }
    return prev;
}

//std::shared_ptr<ast::Program> Parser::produceAST(std::string sourceCode) {
//    tokens = tokenize(sourceCode);
//    std::shared_ptr<ast::Program> program;
//    while(not_eof()){
//        program->body.push_back(parse_stmt());
//    }
//    return program;
//}

ast::Program Parser::produceAST(std::string sourceCode) {
    tokens = tokenize(sourceCode);
    ast::Program program;
    while(not_eof()){
        program.body.push_back(parse_stmt());
    }
    return program;
}

std::shared_ptr<ast::Stmt> Parser::parse_stmt(){
    return parse_expr();
}

ExprPtr Parser::parse_expr(){
    return parse_additive_expr();
}

ExprPtr Parser::parse_additive_expr() {
    std::shared_ptr<ast::Expr> left = this->parse_multiplicative_expr();
    while(at().value == "+" || at().value == "-"){
        std::string op = eat().value;
        std::shared_ptr<ast::Expr> right = parse_multiplicative_expr();
        left = std::make_shared<ast::BinaryExpr>(left, op, right);
    }
    return left;
}

ExprPtr Parser::parse_multiplicative_expr() {
    std::shared_ptr<ast::Expr> left = this->parse_primary_expr();
    while(at().value == "*" || at().value == "/" || at().value == "%"){
        std::string op = eat().value;
        std::shared_ptr<ast::Expr> right = parse_primary_expr();
        left = std::make_shared<ast::BinaryExpr>(left, op, right);
    }
    return left;
}

ExprPtr Parser::parse_primary_expr(){
    TokenType tk = at().type;
    switch(tk){
        case TokenType::Identifier: {
            std::shared_ptr<ast::Identifier> ident = std::make_shared<ast::Identifier>(eat().value);
            return ident;
        }
        case TokenType::Number: {
            std::shared_ptr<ast::NumericLiteral> numLiteral = std::make_shared<ast::NumericLiteral>(std::stod(eat().value));
            return numLiteral;
        }
        case TokenType::Null: {
            eat();
            return std::make_shared<ast::NullLiteral>();
        }
        case TokenType::OpenParen: {
            eat();
            std::shared_ptr<ast::Expr> contents = parse_expr();
            expect(TokenType::CloseParen, "Unexpected token found. Expected ')'");
            return contents;
        }
        default:
            std::cout << "Unexpected token found: " << at().value << std::endl;
            exit(EXIT_FAILURE);
    }
}