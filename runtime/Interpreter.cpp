//
// Created by kemal on 01/11/2023.
//

#include "../Ast.h"
#include "ValueType.h"
#include "Interpreter.h"
#include <iostream>

using ast::ExprPtr;

typedef std::shared_ptr<RuntimeVal> RuntimeValPtr;

RuntimeValPtr eval_numeric_binary_expr(std::shared_ptr<NumberValue> lhs, std::shared_ptr<NumberValue> rhs, std::string op){
    double result = 0;
    if(op == "+"){
        result = lhs->value + rhs->value;
    }else if(op == "-"){
        result = lhs->value - rhs->value;
    }else if(op == "*"){
        result = lhs->value * rhs->value;
    }else if(op == "/"){
        // No division by zero checks
        result = lhs->value / rhs->value;
    }else{
        //Add real checks for modulus
        result = int(lhs->value) % int(rhs->value);
    }

    return std::make_shared<NumberValue>(result);
}

RuntimeValPtr evaluate_program(ast::Program program){
    RuntimeValPtr lastEvaluated = std::make_shared<NullValue>();
    for(auto statement : program.body){
        lastEvaluated = evaluate(statement);
    }
    return lastEvaluated;
}

RuntimeValPtr evaluate_binary_expr(std::shared_ptr<ast::BinaryExpr> binop){
    RuntimeValPtr lhs = evaluate(binop->left);
    RuntimeValPtr rhs = evaluate(binop->right);

    if(lhs->type == ValueType::Number && rhs->type == ValueType::Number){
        std::shared_ptr<NumberValue> l = std::static_pointer_cast<NumberValue>(lhs);
        std::shared_ptr<NumberValue> r = std::static_pointer_cast<NumberValue>(rhs);
        return eval_numeric_binary_expr(l, r, binop->_operator);
    }
    return std::make_shared<NullValue>();
}

RuntimeValPtr evaluate(std::shared_ptr<ast::Stmt> astNode){
    switch (astNode->kind) {
        case NodeType::NumericLiteral: {
            std::shared_ptr<ast::NumericLiteral> node = std::static_pointer_cast<ast::NumericLiteral>(astNode);
            return std::make_shared<NumberValue>(node->number);
        }
        case NodeType::NullLiteral:
            return std::make_shared<NullValue>();
        case NodeType::BinaryExpr:
            return evaluate_binary_expr(std::static_pointer_cast<ast::BinaryExpr>(astNode));
        case NodeType::Program:
            return evaluate_program(*std::static_pointer_cast<ast::Program>(astNode));
        default:
            std::cout << "This node has not yet been implemented" << std::endl;
            exit(0);
    }
}