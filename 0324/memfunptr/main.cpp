#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Wedget{
public:
    int funx(){return 0;};
    int funy(){return 1;};
    float funz(){return 2.0;};
    static int funs() {return 3.0;};

    virtual int funv() {return 4.0;};
};

int main() {
    Wedget *ptr = new Wedget;
    int (Wedget::*fun)();
    int (*funn)();

    fun = &Wedget::funx;
    std::cout << (ptr->*fun)() << std::endl;

    fun = &Wedget::funy;
    std::cout << (ptr->*fun)() << std::endl;

    funn = (int(*)())&Wedget::funy;
    std::cout << funn() << std::endl;

    printf("location:%p\n", &Wedget::funx);
    printf("location:%p\n", &Wedget::funy);
    printf("location:%d\n", &Wedget::funz);
    printf("location:%d\n", &Wedget::funs);

    
    printf("location:%p\n", &Wedget::funv);
    printf("sizeof ptr:%d\n", sizeof(int*));
    //printf("location:%p\n", &Wedget::~Wedget);
    
    delete ptr;
}
