#include <iostream>
#include <string>
#include "Counter.h"
int main() {
    Counter<string> *counter = new Counter<string>;
    counter->add_from_stream(cin);
    counter->print_to_stream(cout);
    counter->print_most_common(cout);


    delete counter;
    return 0;
}
