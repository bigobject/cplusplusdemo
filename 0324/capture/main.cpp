#include <iostream>
using namespace std;



int main() {
    static int count =1;

    auto lam = [input=count](){std::cout << input << std::endl;};

    count ++;
    lam();

    std::cout << "hello world!" << std::endl;
}
