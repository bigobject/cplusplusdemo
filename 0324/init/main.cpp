#include <iostream>
#include <mutex>
#include<memory> 
#include<atomic>
using namespace std;

typedef int length;

class Wedget{
public:
    Wedget() {std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__<< std::endl;}
    Wedget(const Wedget&) {std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__<< std::endl;}
    
    length len;
};

class Level {
public:
    Level() {std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__<< std::endl;}

    static Wedget ms_wedget;
};

Wedget Level::ms_wedget = Wedget();

int main() {
    std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << std::endl;
    static Level level;
    Level::ms_wedget = Wedget();
}
