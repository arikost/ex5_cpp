//
// Created by USER on 6/21/2021.
//

#ifndef EX5_CPP_PARSER_H
#define EX5_CPP_PARSER_H
#include "Counter.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Parser{
private:
    vector<Counter<T> > _counters;
public:
    void start(){

    }
    void add_counter(string type, string name){
        for (int i = 0; i < _counters.size(); ++i) {
            if(_counters[i].getName() == name){
                cerr << "Counter name already exists"<<endl;
                exit(1);
            }
        }
        if(type == "int_counter"){
            _counters.push_back(new Counter<int>(name));
        }
        else if(type == "string_counter"){

        }
    }
};



#endif //EX5_CPP_PARSER_H
