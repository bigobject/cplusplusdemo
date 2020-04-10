#include <iostream>
#include <typeinfo>
#include "handle.h"

using namespace std;


int main() {
    Handle a(3, 23.2);
    std::cout << a << std::endl;
    a->Seti(4);
    std::cout << a << std::endl;

    Handle b = a;
    std::cout << b << std::endl;

    b->Seti(2);
    std::cout << b << std::endl;
}
