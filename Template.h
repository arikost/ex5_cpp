//
// Created by USER on 6/22/2021.
//

#ifndef EX5_CPP_TEMPLATE_H
#define EX5_CPP_TEMPLATE_H
#include <string>
using namespace std;
class Template{
private:
    string name;
public:
    virtual ~Template(){};
    virtual string getType() = 0;
    virtual string getName() = 0;
    virtual bool isEmpty() = 0;
    virtual void print_to_stream(ostream& out) =0;
    virtual void print_most_common(ostream& out) = 0;
    };
#endif //EX5_CPP_TEMPLATE_H
