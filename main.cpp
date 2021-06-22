#include "parser.h"

using namespace std;


int main() {
    Counter<int> *c = new Counter<int>("c");
    Counter<string> *s = new Counter<string>("c");
    Template *t1;
    t1 = s;
    if(t1)
    return 0;
}
