#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

typedef float length;
class Wedget{
public:
    Wedget(length x):len(x) {};
    virtual length getlen() final {return len;};
    void setlen(length _len){len = _len;};

private:
    length len;
};

class drived :public Wedget {
public:
	drived():Wedget(0) {};
};


int main() {
    Wedget x(2);
    std::cout << "len:" << x.getlen() << std::endl;

    x.setlen(4);
    std::cout << "len:" << x.getlen() << std::endl;


    drived tt;
    tt.setlen(5);
    std::cout << "len:" << tt.getlen() << std::endl;

}
