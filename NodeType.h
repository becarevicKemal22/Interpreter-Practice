//
// Created by kemal on 12/09/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V1_NODETYPE_H
#define PROGRAMMING_LANGUAGE_V1_NODETYPE_H

#include <string>

enum class NodeType {
    Program,
    NumericLiteral,
    NullLiteral,
    Identifier,
    BinaryExpr
};

std::string nodeTypeToString(NodeType type);

#endif //PROGRAMMING_LANGUAGE_V1_NODETYPE_H
