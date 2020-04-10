#include <iostream>
#include <mutex>
#include<memory> 
#include<atomic>
using namespace std;

typedef int length;

class Wedget{
public:
    Wedget(int _len):len(_len) {}
    
    length getlen() {
        std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << std::endl;
        std::cout << "len:" << len << std::endl;
        return len;
    };
    length getlen()const {
        std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << std::endl;
        std::cout << "len:" << len << std::endl;
        return len;
    };
    length len;
};

const Wedget g_cwedget(5);

int main() {
    std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << std::endl;
    Wedget wedget (3);
    const Wedget cwedget (3);
    wedget.getlen();
    cwedget.getlen();

    std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << std::endl;
    g_cwedget.getlen();
    Wedget& rwedget = const_cast<Wedget&>(g_cwedget);
    rwedget.len = 8;
    rwedget.getlen();
    g_cwedget.getlen();


}
