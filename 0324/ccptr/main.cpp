#include <iostream>
#include <typeinfo>
#include "ccptr.h"

using namespace std;


int main() {
    Ccptr<int> a(3);
    std::cout << a << std::endl;

    Ccptr<int> b = a;
    std::cout << b << std::endl;

    Ccptr<Data> c(3,4.2);
    std::cout << c << std::endl;
    c->Seti(4);
    std::cout << c << std::endl;
    
    Data& dd = (Data)*c.m_pdata;
    std::cout << dd << std::endl;
}
