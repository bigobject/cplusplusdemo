#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

class point2d {
public:
friend class point3d;
    int x;
private:
    point2d() {};
};

class point3d : public virtual point2d{
public:
    int z;
    point3d() {};
};

class point4d :public point3d {
public :
    int k;
};

int main() {
    point3d d;
    //point4d k;
}
