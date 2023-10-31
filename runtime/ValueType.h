//
// Created by kemal on 31/10/2023.
//

#ifndef PROGRAMMING_LANGUAGE_V2_VALUETYPE_H
#define PROGRAMMING_LANGUAGE_V2_VALUETYPE_H

enum class ValueType {
    Null,
    Number,
};

class RuntimeVal {
public:
    RuntimeVal() = default;
    ValueType type;
};

class NullValue : RuntimeVal {
public:
    NullValue() : RuntimeVal(){
        type = ValueType::Null;
    }
};

class NumberValue : RuntimeVal {
public:
    NumberValue(double val) : RuntimeVal() {
        value = val;
    }
    double value;
};

#endif //PROGRAMMING_LANGUAGE_V2_VALUETYPE_H
