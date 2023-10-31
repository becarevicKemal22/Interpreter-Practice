#include <iostream>
#include <memory>

#include "Parser.h"
#include "Ast.h"

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
        cout << "\n" << endl;
        program.printDebug();
    }
}

int main() {
    repl();
    return 0;
}
