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

RuntimeValPtr evaluate(ExprPtr astNode){
    switch (astNode->kind) {
        case NodeType::NumericLiteral: {
            std::shared_ptr<ast::NumericLiteral> node = reinterpret_cast<std::shared_ptr<ast::NumericLiteral>>(astNode);
            return std::make_shared<ValueType::Number>()
        }
    }
}

#endif //PROGRAMMING_LANGUAGE_V2_INTERPRETER_H
