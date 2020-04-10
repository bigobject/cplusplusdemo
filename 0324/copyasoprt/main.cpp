#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef int length;

class Point{
public:
    Point(int x, int y):_x(x), _y(y) {};
    Point& operator = (const Point &rhs) {
        std::cout << "called Point copy operator = " << std::endl;
        _x = rhs._x;_y = rhs._y; return *this;
    };

public:
    int _x,_y;
};

class Point3d : virtual public Point{
public:
    Point3d(int x, int y, int z):Point(x, y), _z(z) {};
    Point3d(const Point3d& p):Point(p._x, p._y), _z(p._z){};   
public : 
    int _z; 
};

class Vertex : virtual public Point{
public:
    Vertex(int x, int y, int mum):Point(x, y), _mumber(mum) {};
public :
    int _mumber;
};

class Vertex3d : public Point3d, public Vertex {
public: 
    Vertex3d(int x, int y, int z, int mum): Point(x,y),Point3d(x, y, z), Vertex(x, y, mum){};
    Vertex3d(const Vertex3d& p): Point(p._x,p._y) ,Point3d(p._x, p._y, p._z), Vertex(p._x, p._y, p._mumber){}; 

};

ostream & operator << (ostream& out, const Vertex3d& rhs) {
    return out << rhs._x << rhs._y << rhs._z << rhs._mumber << std::endl;
}

int main() {
    auto ss = Vertex3d(1,2,3,4);
    auto tt = Vertex3d(5,6,7,8);
    tt = ss;
    std::cout << tt;
    return 0;
}
