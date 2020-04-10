#include <iostream>
using namespace std;

template <typename T>
T f(T t) {
    cout << "T " << t << endl;
};
/*
template <typename T>
T f(const T& t) {
    cout << "const T " << t << endl;
};*/

void fun(int i) {cout << "int " << i << endl;};
/*
void fun(const int& i) const {cout << "const int& " << i << endl;};
*/

class wedget {
public:
    wedget(){};
    void fun(int i) {cout << "int " << i << endl;};
    void fun(int i) const {cout << "const " << i << endl;};
};

//tips: 使用nm test命令可以查看编译后的函数名称，观察修饰规则，
// _ZN6wedget3funEi
// _ZNK6wedget3funEi


int main() {
    f(3);
    fun(4);
    
    const wedget cwd;
    cwd.fun(3);

    wedget wd;
    wd.fun(4);
    
}


