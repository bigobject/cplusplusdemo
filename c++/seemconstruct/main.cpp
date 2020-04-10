#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Wedget{
public:
    Wedget():len(0) {
        std::cout << "construct" << std::endl;
    };

    length len;
};

Wedget t();

int main() {
    Wedget t();
    Wedget f;
}
