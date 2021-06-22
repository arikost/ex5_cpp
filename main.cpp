#include <iostream>
#include <string>
#include "Counter.h"
#include "parser.h"
#include <typeinfo>

int main() {
    fstream file;
    file.open("C:\\Dev\\Clion\\cpp_ex\\ex5_cpp\\מטלת הגשה מספר 5 - קבצי בדיקה-20210621\\test");
    double t;
    file >> t;
    cout << t;
    return 0;
}
