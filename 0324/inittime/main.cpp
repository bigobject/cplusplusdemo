#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Wedget{
public:
    Wedget(length x):len(x) {};
    length getlen() {return len;};
    void setlen(length _len){len = _len;};

private:
    typedef float length;
    length len;
};



int main() {
    Wedget x(2);
    std::cout << "len:" << x.getlen() << std::endl;

    x.setlen(4);
    std::cout << "len:" << x.getlen() << std::endl;
}
