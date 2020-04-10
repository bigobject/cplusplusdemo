#include <iostream>
#include <mutex>
#include<memory> 
#include<atomic>
using namespace std;

#define FOOTPRINT (std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << std::endl)

typedef int length;

class Wedget{
public:
    static Wedget* createWedget() {return new Wedget;};
    ~Wedget(){
        FOOTPRINT;
    };
public:
    Wedget(){
        FOOTPRINT;
    };
    length len;
};

int main() {
    FOOTPRINT;

    auto a = shared_ptr<Wedget> (Wedget::createWedget());

    auto b = Wedget::createWedget();
    delete b;

    auto c = std::make_shared<Wedget>();


}
