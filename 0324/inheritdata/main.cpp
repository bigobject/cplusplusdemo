#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

class Wedget{
protected:
    int len;
};

class Sodier: public Wedget {
protected:
    int level;
};

class Man {
    protected:
    int weight;
};

class Waiter :public Sodier , public Man{
    private:
    string name;
};


int main() {
    Waiter wt;
    Sodier *ps = &wt;
    Wedget *pw = &wt;
    Man * pm = &wt;
    std::cout << "&wt:" << &wt << std::endl;
    std::cout << "ps:" << ps << std::endl;
    std::cout << "pw:" << pw << std::endl;
    std::cout << "pm:" << pm << std::endl;
    std::cout << "sizeof(Sodier):" << sizeof(Sodier) << std::endl;

}
