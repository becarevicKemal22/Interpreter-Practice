//
// Created by kemal on 12/09/2023.
//

#include <unordered_map>
#include "NodeType.h"


std::unordered_map<NodeType, std::string> nodeTypeStringMap = {
        {NodeType::NumericLiteral, "NumericLiteral"},
        {NodeType::NullLiteral, "NullLiteral"},
        {NodeType::Program, "Program"},
        {NodeType::BinaryExpr, "BinaryExpr"},
        {NodeType::Identifier, "Identifier"},
};

std::string nodeTypeToString(NodeType type) {
    auto it = nodeTypeStringMap.find(type);
    if (it != nodeTypeStringMap.end()) {
        return it->second;
    } else {
        return "Unknown"; // Handle unknown enum values
    }
}