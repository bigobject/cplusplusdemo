#include <iostream>
using namespace std;

class point {
public:
    point():x(0){};
private:
    int x;
};

class point2d :public point {
public:
    point2d():y(0){};
private:
    int y;
};

int main() {
    point* pt = new point2d;

    point2d* pt2 = dynamic_cast<point2d*>(pt);

    if (pt2 == nullptr) {
        std::cout<<"dynamic_cast failed"<<std::endl;
    }else {
        std::cout<<"dynamic_cast success"<<std::endl;
    }
}


