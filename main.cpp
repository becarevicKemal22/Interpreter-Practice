#include <iostream>
#include <memory>

#include "Parser.h"
#include "Ast.h"
#include "./runtime/Interpreter.h"

using namespace std;

void repl(){
    cout << "Repl v0.1" << endl;
    Parser parser;
    for(;;){

        cout << endl << "> ";
        string input;
        getline(cin, input);
        if(input.empty()){
            exit(0);
        }
        ast::Program program = parser.produceAST(input);
        program.print();
//        cout << "\n" << endl;
//        program->printDebug();
        std::shared_ptr<RuntimeVal> value = evaluate_program(program);
        std::cout << std::endl << "-----------" << std::endl;
        value->print();
    }
}

int main() {
    repl();
    return 0;
}
