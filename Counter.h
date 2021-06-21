//
// Created by Admin on 6/16/2021.
//

#ifndef EX5_CPP_COUNTER_H
#define EX5_CPP_COUNTER_H
#include <vector>
#include <iostream>

using namespace std;
template <class T>
class Counter{
private:
    vector<T> _values;
    vector<unsigned int> _counters;
public:
    void clear(){
        _values.clear();
        _counters.clear();
    }
    void add(const T& t){
        for(int i=0; i < _values.size(); i++){
            if(_values[i] == t){
                _counters[i]++;
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
        if(_values.empty()){
            throw exception;
        }
        int t = 0;
        T* ptr = _values[0];
        for (int i = 0; i < _values.size(); ++i) {
            if(_counters[i] > t && ptr > _values[i] ){
                ptr = _values[i];
                t = _counters[i];
            }
        }
        return *ptr;
    }

};



#endif //EX5_CPP_COUNTER_H
