//
// Created by kemal on 31/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_INTERPRETER_H
#define PROGRAMMING_LANGUAGE_V2_INTERPRETER_H

#include <memory>
#include "../Ast.h"
#include "ValueType.h"

using ast::ExprPtr;

typedef std::shared_ptr<RuntimeVal> RuntimeValPtr;

RuntimeValPtr evaluate_program(ast::Program program);
RuntimeValPtr evaluate_binary_expr(std::shared_ptr<ast::BinaryExpr> binop);
RuntimeValPtr evaluate(std::shared_ptr<ast::Stmt> astNode);

#endif //PROGRAMMING_LANGUAGE_V2_INTERPRETER_H
