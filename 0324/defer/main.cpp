#include <iostream>
#include "defer.h"
#include "defer1.h"
#include "defer2.h"

using namespace std;

void fun() {
    std::cout << "call fun" << std::endl;
}

class objecfun {
public:
    void operator() (){
        std::cout << "call objecfun" << std::endl;
    };
};

#define bigger(a,b) (((long long)(a) - (long long)(b))>>63?false:true)
int main() {
    //defer std::cout << "do anything defer" << std::endl;        //best but imposible
    //defer b([=]{std::cout << "do anything defer"<< std::endl;}); //support

    defer (std::cout << "do anything defer:" << " \'cout 1:" << "\'"<< std::endl;); 
    defer (std::cout << "do anything defer:" << " \'cout 2:" << "\'"<< std::endl;); 
    defer (std::cout << "do anything defer 3" << std::endl;); 

    //defer (fun);
    //defer (obj);
    //defer b = a  //support 

    //defer *b = new([]{std::cout << "do anything defer"<< std::endl;})  //delete operator new
    
    defer1 (std::cout<<"defer 1"<<std::endl);
    std::cout<<"pos 1"<<std::endl;
    {
        defer1 (std::cout<<"defer 2"<<std::endl);
        defer1 (std::cout<<"defer 3"<<std::endl);
        std::cout<<"pos 2"<<std::endl;
    }
    std::cout<<"pos 3"<<std::endl;
    defer1 (fun);

    unsigned int a1 = 1;
    unsigned int a2 = 2;
    std::cout << a1 << " > " << a2 << ": " << bigger(a1,a2) << std::endl;

    int i1 = 3;
    int i2 = 2;
    std::cout << i1 << " > " << i2 << ": " << bigger(i1,i2) << std::endl;


    defer2 (std::cout<<"defer2 1"<<std::endl);
    defer2 (std::cout<<"defer2 2"<<std::endl);
}
