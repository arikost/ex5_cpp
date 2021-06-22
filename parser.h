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
#include <d2d1helper.h>

using namespace std;


class Parser{
private:
    vector<Template> _counters;
public:
    void start(){
        string cmd, counter_name, file_name, values,line;
        while(getline(cin, line)){
            int index = 0;
            cmd = get_input_from_line(line, index);
            if(index == line.length()){
                //exception
            }
            if(cmd == "int_counter"){
                counter_name = get_input_from_line(line, index);
                add_counter("int_counter", counter_name);
            }
            else if(cmd == "string_counter"){
                counter_name = get_input_from_line(line, index);
                add_counter("string_counter", counter_name);
            }
            else if(cmd == "add_from_file"){
                counter_name = get_input_from_line(line, index);
                if(index == line.length()){
                    //exception
                }
                file_name = get_input_from_line(line, index);
                add_from_file(counter_name, file_name);
            }
            else if(cmd == "add_from_string"){
                counter_name = get_input_from_line(line, index);
                if(index == line.length()){
                    //exception
                }
                values = get_input_from_line(line, index);
                add_from_string(counter_name, values);
            }
            else if(cmd == "stats"){
                counter_name = get_input_from_line(line, index);
                stats(counter_name);
            }
            else if(cmd == "most_common"){
                counter_name = get_input_from_line(line, index);
                most_common(counter_name);
            }else{
            //exception
            }
            cmd.clear();
            counter_name.clear();
            file_name.clear();
            values.clear();
        }
    }
    string get_input_from_line(const string& line, int& index){
        string str;
        while(index < line.length()){
            if(line[index] == ' ') {
                index++;
                break;
            }
            str += line[index];
            index++;
        }
        return str;
    }

    void add_counter(string type, string name){
        Counter<int> ci;
        Counter<string> *cs;
        for (int i = 0; i < _counters.size(); ++i) {
            if(_counters[i].getType() == typeid(int).name()){
                *ci = dynamic_cast<Counter<int>& >(_counters[i]);
            }
            else{
                *cs = dynamic_cast<Counter<string>& >(_counters[i]);
            }

            if(ci->getName() == name || cs->getName() == name){
                throw MyException("Counter name already exists");
            }
        }
        if(type == "int_counter"){
            _counters.push_back(Counter<int>(name));
        }
        else if(type == "string_counter"){
            _counters.push_back(Counter<string>(name));
        }
    }
    void add_from_file(string counter_name, string file_name){
        int j = get_counter(counter_name);
        fstream file;
        file.open(file_name.c_str());
        string word;
        if(file.fail()){
            throw MyException("Failed to open file");
        }
        if(_counters[j].getType() == typeid(int).name()){
            int x;
            while(file >> word){
                x = pars_int(word);
                _counters[j].add(x);
            }
        }
        else {
            /**
             * the type is string
             */
            while (file >> word) {
                _counters[j].add(word);
            }
        }
    }
    void add_from_string(string counter_name, string values){
        int j = get_counter(counter_name);
        if(_counters[j].getType() == typeid(int).name()){
            int x, i=0;
            string int_val;
            while(i < values.length()) {
                if(values[i] == ' '){
                    x = pars_int(int_val);
                    _counters[j].add(x);
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
             int i = 0;
             string string_val;
             while(i < values.length()) {
                 if(values[i] == ' '){
                     _counters[j].add(string_val);
                     string_val.clear();
                 } else{
                     string_val += values[i];
                 }
                 i++;
             }
        }
    }
    void stats(string counter_name){
        int j = get_counter(counter_name);
        if(_counters[j].isEmpty()){
            throw MyException("Error: Counter is empty");
        }
        cout << "counter " << counter_name<< " = ";
        _counters[j].print_to_stream(cout);
    }
    void most_common(string counter_name){
        int j = get_counter(counter_name);
        if(_counters[j].isEmpty()) {
            throw MyException("Error: Counter is empty");
        }
        cout <<"most common element for counter "<< _counters[j].getName()<< " is ";
        _counters[j].print_most_common(cout);
    }
    int pars_int(string basicString) {
        for(int i=0; i < basicString.length(); i++){
            if(basicString[i] < '0' || basicString[i] > '9'){
                throw MyException("Read failed");
            }
        }
        return atoi(basicString.c_str());
    }
    int get_counter(string counter_name){
        bool flag = true;
        int j;
        for (int i = 0; i < _counters.size(); ++i) {
            if(_counters[i].getName() == counter_name){
                flag = false;
                j = i;
                break;
            }
        }
        if(flag){
            throw MyException("No counter named ");
        }
        return j;
    }
};



#endif //EX5_CPP_PARSER_H
