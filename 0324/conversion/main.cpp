#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Y {
    
public:
    bool operator == (const Y& ) const {return false;};
};

class X {

public:
    operator bool () const{return false;};
    X getValue(){return *this;};
};

int main() {
    X xx;
    Y yy;
    if (yy == xx.getValue()) {
        std::cout << "equal" << std::endl;
    }

}
