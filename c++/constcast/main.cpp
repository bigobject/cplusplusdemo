#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

void f(const int &i) {
    const_cast<int&>(i) = 2;
    std::cout << "f i:" << i  << ", &i:" << &i << std::endl;
}

int main() {
    int a = 0;
    const int ca = 0;

    int &r = a;
    const int &cr = ca;

    const_cast<int&>(cr) = 1;
    std::cout << "const int ca:" << cr << ", &cr:"<< &cr <<std::endl;

    const int &cra = a;

    f(r);

    std::cout << "int a:" << a << ", &a:"<< &a <<std::endl;

    f(cr);
    std::cout << "const int ca:" << ca << ", &ca:"<< &ca <<std::endl;

}
