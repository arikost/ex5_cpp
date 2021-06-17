//
// Created by Admin on 6/16/2021.
//

#ifndef EX5_CPP_COUNTER_H
#define EX5_CPP_COUNTER_H
#include <vector>


template <class T>
class Counter{
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
        for (int i = 0; i < _.size(); i++) {
            if (_values[i] == t) {
                return _counters[i];
            }
        }
        return 0;
    }
    T&
private:
    vector<T> _values;
    vector<unsigned int> _counters;

};



#endif //EX5_CPP_COUNTER_H
