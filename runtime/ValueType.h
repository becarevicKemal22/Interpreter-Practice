//
// Created by kemal on 31/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_VALUETYPE_H
#define PROGRAMMING_LANGUAGE_V2_VALUETYPE_H

#include <iostream>

enum class ValueType {
    Null,
    Number,
};

class RuntimeVal {
public:
    RuntimeVal() = default;
    virtual ~RuntimeVal() = default;
    ValueType type;
    virtual void print(){
        std::cout << "Generic value" << std::endl;
    }
};

class NullValue : public RuntimeVal {
public:
    NullValue() : RuntimeVal(){
        type = ValueType::Null;
    }
    void print() override {
        std::cout << "null" << std::endl;
    }
};

class NumberValue : public RuntimeVal {
public:
    NumberValue(double val) : RuntimeVal() {
        type = ValueType::Number;
        value = val;
    }
    double value;
    void print() override {
        std::cout << value << std::endl;
    }
};

#endif //PROGRAMMING_LANGUAGE_V2_VALUETYPE_H
