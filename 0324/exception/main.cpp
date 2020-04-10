#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Wedget{
public:
    Wedget(length x):len(x) {
	std::cout << "destroy Wedget with len:" << len << std::endl;
    };

    length GetLen(){return len;};

private:
    length len;
};

void exceptfun();
void caller() noexcept;
void called();
int main() {
    try{
        auto a = Wedget(5);
	//exceptfun();
	caller();
    }catch(int e){
        std::cout << "get exception:" << e << std::endl;
    }
}

void exceptfun() {
    try {
        auto a = Wedget(5);
        if (a.GetLen() < 5) {
            throw(a.GetLen());
        } 
        auto b = Wedget(4);
        if (b.GetLen() < 4) {
            throw(b.GetLen());
        } 

    }catch(int e) {
        throw(e);
    }

    return;
}

void caller() noexcept{
    auto a = Wedget(4);
    called();
}

void called() {
    throw(9);
}
