#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Wedget{
public:
    bool funa() {return true;};
    bool funb(int a) { return funa();};
};

class Drived :public Wedget {
public:
    bool funa() {return false;};
    bool funb(int a) { return funa();};
};


int main() {
    Wedget w;
    std::cout << w.funa() <<std::endl;
    Drived a;
    std::cout << a.funa() <<std::endl;

    Wedget *ptr = &a;
    std::cout << ptr->funa() <<std::endl;
    
}
