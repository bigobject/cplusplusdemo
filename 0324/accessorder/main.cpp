#include <iostream>
#include<assert.h>


using namespace std;

typedef int length;

class Wedget{
public:
    int x;
public:
    int y;
public:
    int z;
};

template<class classtype, class typelhs, class typerhs>
char* access_order(typelhs classtype::*lhs, typerhs classtype::*rhs) {
    assert (lhs != rhs);
    return (void*) lhs < (void*)rhs ? "lhs fisrt" : "rhs first";
}

int main() {
    std::cout << access_order(&Wedget::x, &Wedget::y) << std::endl;

}
