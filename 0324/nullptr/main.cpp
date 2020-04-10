#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;
class Wedget{
    int _data;
};

int fun1(std::shared_ptr<Wedget> spw){return 0;};
double fun2(std::unique_ptr<Wedget> upw){return 0.0;};
bool fun3(Wedget* pw){return true;};

using lockguard = std::lock_guard<std::mutex>;

template<typename functype, 
        typename locktype, 
        typename ptrtype>
auto LockandCall(functype fun, locktype& lock, ptrtype ptr) ->decltype(fun(ptr)) {
    lockguard my(lock);
    std::cout << "call " << typeid(fun).name() << " success" << endl;
    return fun(ptr);
}

int main() {
    std::mutex f1,f2,f3;

    LockandCall(fun1, f1, nullptr);
    LockandCall(fun2, f2, nullptr);
    LockandCall(fun3, f3, nullptr);
    std::cout << "hello world!" << endl;
}
