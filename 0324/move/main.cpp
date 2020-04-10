#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;
class Wedget{
public:
    Wedget() {
        _pdata = new int;
    }

    void Set(int i) {_pdata != nullptr? *_pdata=i:i=i;}
    int Get()const {
        if (nullptr == _pdata)
            return 0;
        return *_pdata;
    }

    Wedget(const Wedget& lvalue){
        _pdata = new int;
        *_pdata = *lvalue._pdata;
        std::cout << "copy construct" << std::endl;
    }

    Wedget(Wedget&& rvalue){
        _pdata = rvalue._pdata;
        rvalue._pdata = nullptr;
    };

    Wedget& operator = (Wedget&& rvalue){
        if (this == &rvalue) {
            std::cout << "move same object" << std::endl;

            return *this;
        }

        if (_pdata != nullptr) {
            delete _pdata;
            _pdata = nullptr;
        } 

        _pdata = rvalue._pdata;
        rvalue._pdata = nullptr;
        return *this;
    };
    ~Wedget() {
        if (_pdata != nullptr)
            delete _pdata;
        _pdata=nullptr;
    };
private:
    int* _pdata;
};

int main() {
    Wedget a;
    a.Set(3);

    Wedget b(std::move(a));
    std::cout << "a:" << a.Get() << ", b:" << b.Get() << std::endl;

    Wedget c(std::move(b));
    std::cout << "b:" << a.Get() << ", c:" << c.Get() << std::endl;
    c=std::move(c);
    std::cout << "b:" << a.Get() << ", c:" << c.Get() << std::endl;

    const Wedget d(c);
    std::cout << "c:" << c.Get() << ", d:" << d.Get() << std::endl;

    Wedget e(std::move(d));
    std::cout << "d:" << d.Get() << ", e:" << e.Get() << std::endl;

    Wedget f(e);
    std::cout << "e:" << e.Get() << ", f:" << f.Get() << std::endl;

}
