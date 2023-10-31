//
// Created by kemal on 31/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_AST_H
#define PROGRAMMING_LANGUAGE_V2_AST_H

#include <vector>
#include <memory>
#include "NodeType.h"

namespace ast {

    class Expr;
    typedef std::shared_ptr<ast::Expr> ExprPtr;

    class Stmt {
    public:
        NodeType kind;
        Stmt() = default;
        virtual ~Stmt() = default;
        virtual void print(){
            std::cout << "Generic Statement!" << std::endl;
        }
    };

    class Program : public Stmt {
    public:
        Program() : Stmt(){
            kind = NodeType::Program;
            body = {};
        }
        std::vector<std::shared_ptr<Stmt>> body;
        void print() override{
            std::cout << "Printing AST" << std::endl;
            for(auto stmtPtr : body){
                stmtPtr->print();
            }
        }
    };
//
//    class Expr;
//    class BinaryExpr;
//    class Identifier;
//    class NumericLiteral;

    class Expr : public Stmt {
    public:
        Expr() = default;

        void print() override {
            std::cout << "Generic statement!" << std::endl;
        }
    };

    class BinaryExpr : public Expr {
    public:
        BinaryExpr(ExprPtr left, std::string _operator, ExprPtr right) : Expr() {
            kind = NodeType::BinaryExpr;
            this->left = left;
            this->right = right;
            this->_operator = _operator;
        }
        ExprPtr left{}, right{};
        std::string _operator;
    };

    class Identifier : public Expr {
    public:
        Identifier(std::string symbol) : Expr() {
            kind = NodeType::Identifier;
            this->symbol = symbol;
        }
        std::string symbol;
        void print() override{
            std::cout << "[Identifier] " << symbol << " " << std::endl;
        }
    };

    class NumericLiteral : public Expr {
    public:
        NumericLiteral(double number) : Expr(){
            kind = NodeType::NumericLiteral;
            this->number = number;
        }
        double number;
        void print() override{
            std::cout << "[NumLiteral] " << number << std::endl;
        }
    };

//    class NullLiteral : public Expr {
//    public:
//        NullLiteral() : Expr(){
//            kind = NodeType::NullLiteral;
//        }
//    };
}

#endif //PROGRAMMING_LANGUAGE_V2_AST_H
