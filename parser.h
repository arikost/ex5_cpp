//
// Created by USER on 6/21/2021.
//

#ifndef EX5_CPP_PARSER_H
#define EX5_CPP_PARSER_H
#include "Counter.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>

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
            _counters.push_back(new Counter<string>(name));
        }
    }


    void add_from_file(string counter_name, string file_name){
        bool flag = false;
        int j;
        for (int i = 0; i < _counters.size(); ++i) {
            if(_counters[i].getName() == counter_name){
                flag = true;
                j = i;
                break;
            }
        }
        fstream file;
        file.open(file_name.c_str());
        string word;
        if(file.fail()){
            cerr << "Failed to open file"<<endl;
            exit(1);
        }
        if(_counters[j].getType() == typeid(int).name()){
            int x;
            while(file >> word){
                x = pars_int(word);
                _counters[j].add(x);
            }
        }
        else{
            /**
             * the type is string
             */


        }



    }

    int pars_int(string basicString) {
        return 0;
    }
    string pars_string(string basicString) {
        return 0;
    }

};



#endif //EX5_CPP_PARSER_H
