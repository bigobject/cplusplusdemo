#include <iostream>
#include <typeinfo>

using namespace std;



template <typename T> 
void f(T& t) {
    cout << "typeid(t).name()" << typeid(t).name() 
        << ", typeid(T).name():" << typeid(T).name() 
        << ", &t:" << &t << endl;
};


template <typename T> 
void fa(T&& t) {
    cout << "typeid(t).name()" << typeid(t).name() 
        << ", typeid(T).name():" << typeid(T).name() 
        << ", &t:" << &t << endl;
};



int main() {
    int x = 1;
    const int cx = 1;
    const int& rx = 1;
    int && rhx = 1;
    cout << "&x:" << &x << endl;
    cout << "&cx:" << &cx << endl;
    cout << "&rx:" << &rx << endl;
    cout << "&rhx:" << &rhx << endl;
    f(x);
    f(cx);
    f(rx);
    f(rhx);

    fa(x);
    fa(cx);
    fa(rx);
    fa(rhx);

    int* px = &x;
    int* &rpx = px;


    fa(px);
    fa(rpx);
    
    
}


