//
// Created by USER on 6/21/2021.
//

#ifndef EX5_CPP_PARSER_H
#define EX5_CPP_PARSER_H
#include "Template.h"
#include "Counter.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;


class Parser{
private:
    vector<Template*> _counters;
public:
    void start(){
        _counters.clear();
        string cmd, counter_name, file_name, values,line;
        while(getline(cin, line)){
            int index = 0;
            cmd = get_input_from_line(line, index, "cmd");
            if(cmd == "int_counter"){
                counter_name = get_input_from_line(line, index, "counter_name");
                add_counter("int_counter", counter_name);
            }
            else if(cmd == "string_counter"){
                counter_name = get_input_from_line(line, index, "counter_name");
                add_counter("string_counter", counter_name);
            }
            else if(cmd == "add_from_file"){
                counter_name = get_input_from_line(line, index, "counter_name");
                file_name = get_input_from_line(line, index, "file_name");
                add_from_file(counter_name, file_name);
            }
            else if(cmd == "add_from_string"){
                counter_name = get_input_from_line(line, index, "counter_name");
                values = get_input_from_line(line, index, "values");
                add_from_string(counter_name, values+" ");
            }
            else if(cmd == "stats"){
                counter_name = get_input_from_line(line, index, "counter_name");
                stats(counter_name);
            }
            else if(cmd == "most_common"){
                counter_name = get_input_from_line(line, index, "counter_name");
                most_common(counter_name);
            }else{
                throw MyException("Error: Unknown command "+cmd);
            }
            cmd.clear();
            counter_name.clear();
            file_name.clear();
            values.clear();
        }
    }
    string get_input_from_line(const string& line, int& index, string parameter){
        string str;
        if(index == line.length()){
            if( parameter == "counter_name"){
                throw MyException("Error: Missing counter name");
            }
            else if( parameter == "file_name"){
                throw MyException("Error: Missing file name");
            }
        }

        while(index < line.length()){
            if(line[index] == ' ' && parameter != "values") {
                index++;
                break;
            }
            str += line[index];
            index++;
        }
        return str;
    }

    void add_counter(string type, string name) {
        if(_counters.size() != 0) {
            Template *t = get_counter(name);
            if (t != NULL) {
                throw MyException("Error: Counter name already exists");
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
        Template *t = get_counter(counter_name);
        if(t == NULL){
            throw MyException("Error: No counter named "+counter_name);
        }
        fstream file;
        file.open(file_name.c_str());
        string word;
        if(file.fail()){
            throw MyException("Error: Failed to open file");
        }
        if(t->getType() == typeid(int).name()){
            Counter<int> *ci = dynamic_cast<Counter<int>* >(t);
            int x;
            while(file >> word){
                x = pars_int(word);
                ci->add(x);
            }
        }
        else {
            /**
             * the type is string
             */
            Counter<string> *cs = dynamic_cast<Counter<string>* >(t);
            while (file >> word) {
                cs->add(word);
            }
        }
    }
    void add_from_string(string& counter_name, string values){
        Template *t = get_counter(counter_name);
        if(t->getType() == typeid(int).name()){
            Counter<int> *ci = dynamic_cast<Counter<int>* >(t);
            int x, i=0;
            string int_val;
            while(i < values.length()) {
                if(values[i] == ' '){
                    x = pars_int(int_val);
                    ci->add(x);
                    int_val.clear();
                }else {
                    int_val += values[i];
                }
                i++;
            }
        }
        else{
            /**
             * type is string
             */
            Counter<string> *cs = dynamic_cast<Counter<string>* >(t);
            int i = 0;
             string string_val;
             while(i <= values.length()) {
                 if(values[i] == ' '){
                     cs->add(string_val);
                     string_val.clear();
                 } else{
                     string_val += values[i];
                 }
                 i++;
             }
        }
    }
    void stats(string counter_name){
        Template *t = get_counter(counter_name);
        if(t ==NULL){
            throw MyException("Error: No counter named "+counter_name);
        }
        cout << "counter " << counter_name<< " = ";
        t->print_to_stream(cout);
    }
    void most_common(string counter_name){
        Template *t = get_counter(counter_name);
        if(t->isEmpty()) {
            throw MyException("Error: Counter is empty");
        }
        cout <<"most common element for counter "<< t->getName()<< " is ";
        t->print_most_common(cout);
    }
    int pars_int(string basicString) {
        for(int i=0; i < basicString.length(); i++){
            if(basicString[i] < '0' || basicString[i] > '9'){
                throw MyException("Error: Read failed");
            }
        }
        return atoi(basicString.c_str());
    }
    Template* get_counter(string counter_name){
        for (int i = 0; i < _counters.size(); ++i) {
            if(_counters[i]->getName() == counter_name){
                 return  _counters[i];
            }
        }
        return NULL;
    }
};



#endif //EX5_CPP_PARSER_H
