#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;
class point2d {
public:
    int x;
    int y;
    virtual ~point2d(){};
};

class point3d : public virtual point2d{
public:
    int z;
    virtual ~point3d(){};
};

class vetex : public virtual point2d{
public:
    vetex *next;
    virtual ~vetex(){};
};

class vetex3d :public vetex,public point3d {
public:
    int mumble;
};


class point {
public:
    virtual ~point(){};
    int x;
};

class base1 {
    public:
    int a;
    char c;
};
class drived :public base1 {
    public:
    char cd;
};

#define OFFSET(structure, member) ((long)&(((structure*)0)->member))
int main() {
    vetex3d wt;
    vetex *pv = &wt;
    point3d *p3 = &wt;
    point2d * p2 = &wt;
    std::cout << "&wt:" << &wt << std::endl;
    std::cout << "pv:" << pv << std::endl;
    std::cout << "p3:" << p3 << std::endl;
    std::cout << "p2:" << p2 << std::endl;

    std::cout << "sizeof(void*):" << sizeof(void*) << std::endl;
    std::cout << "sizeof(point):" << sizeof(point) << std::endl;
    std::cout << "sizeof(point2d):" << sizeof(point2d) << std::endl;
    std::cout << "sizeof(point3d):" << sizeof(point3d) << std::endl;
    std::cout << "sizeof(vetex):" << sizeof(vetex) << std::endl;
    std::cout << "sizeof(vetex3d):" << sizeof(vetex3d) << std::endl;

    
    std::cout << "sizeof(base1):" << sizeof(base1) << std::endl;
    std::cout << "sizeof(drived):" << sizeof(drived) << std::endl;

    std::cout << "OFFSET(point2d, x):" << OFFSET(point2d, x) << std::endl;
    std::cout << "OFFSET(point2d, y):" << OFFSET(point2d, y) << std::endl;

    std::cout << "OFFSET(point3d, z):" << OFFSET(point3d, z) << std::endl;

    std::cout << "OFFSET(vetex, next):" << OFFSET(vetex, next) << std::endl;
    
    std::cout << "OFFSET(vetex3d, z):" << OFFSET(vetex3d, z) << std::endl;
    std::cout << "OFFSET(vetex3d, next):" << OFFSET(vetex3d, next) << std::endl;
    std::cout << "OFFSET(vetex3d, mumble):" << OFFSET(vetex3d, mumble) << std::endl;

    printf("&vetex::next:%p\n", &vetex::next);
}
