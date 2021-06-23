//
// Created by Admin on 6/16/2021.
//

#ifndef EX5_CPP_COUNTER_H
#define EX5_CPP_COUNTER_H
#include <vector>
#include <typeinfo>
#include <iostream>
#include "MyException.h"
#include "Template.h"
using namespace std;
template <class T>
class Counter : public Template{
private:
    string name;
    vector<T> _values;
    vector<unsigned int> _counters;
public:

    Counter(string n) : Template() {
        this->name = n;
    }
    bool isEmpty(){
        return _values.empty();
    }
    string getName(){
        return name;
    }
    string getType(){
        return typeid(T).name();
    }
    void clear(){
        _values.clear();
        _counters.clear();
    }
    void add(const T& t){
        for(int i=0; i < _values.size(); i++){
            if(_values[i] == t){
                _counters[i]++;
                return;
            }
        }
        _values.push_back(t);
        _counters.push_back(1);
    }
    unsigned int  operator[](const T& t)const{
        for (int i = 0; i < _values.size(); i++) {
            if (_values[i] == t) {
                return _counters[i];
            }
        }
        return 0;
    }
    T& most_common(){
        if(isEmpty()){
            throw MyException("Counter is empty");
        }
        int t = _counters[0], j=0;
        for (int i = 1; i < _values.size(); ++i) {
            if(_counters[i] > t ){
                j = i;
                t = _counters[i];
            }
            else if(_counters[i] == t){
                if(_values[j] > _values[i]){
                    j = i;
                }
            }
        }
        return _values[j];
    }
    void add_from_stream(istream& in){
        T ptr;
        while(true){
            in >> ptr;
            if(in.eof()){
                break;
            }
            if(in.fail()){
                throw exception();
            }
            add(ptr);
        }
    }
    void print_to_stream(ostream& out){
        out << "{ ";
        for(int i = 0; i < _values.size(); i++){
            out << _values[i] << ":" << _counters[i] << " ";
        }
        out << "}" << endl;
    }
    void print_most_common(ostream& out) {
        if(isEmpty()){
            throw MyException("Counter is empty");
        }
        T most_com = most_common();
        for (int i = 0; i < _values.size(); ++i) {
            if(_values[i] == most_com){
                out << _values[i] << ":" << _counters[i] << endl;
                break;
            }
        }
    }
};



#endif //EX5_CPP_COUNTER_H
