#include "parser.h"

using namespace std;


int main() {
    Parser *parser;
    try{
        parser->start();
    }catch (MyException exception){
        cerr << exception.getMsg() << endl;
        exit(1);
    }
    return 0;
}
