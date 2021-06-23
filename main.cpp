#include "parser.h"

using namespace std;


int main() {
    Counter<int> *c = new Counter<int>("c");
    Counter<string> *s = new Counter<string>("c");
    cout << c->getType() << endl;
    cout << typeid(int).name();
    return 0;
}
