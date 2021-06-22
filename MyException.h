//
// Created by USER on 6/22/2021.
//

#ifndef EX5_CPP_MYEXCEPTION_H
#define EX5_CPP_MYEXCEPTION_H
#include <string>
using namespace std;
class MyException{
private:
    string msg;
public:
    MyException(string message){
        this->msg = message;
    }
    string getMsg(){
        return msg;
    }
};


#endif //EX5_CPP_MYEXCEPTION_H
