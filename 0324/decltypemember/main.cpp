#include <iostream>
#include <mutex>
#include<memory> 
#include <vector>

using namespace std;
class Wedget{
public:
    Wedget(int i):_data(i),_data2(_data) {};
    int _data;
    decltype(_data) _data2;

};



int main() {

    Wedget x(2);

    std::cout << "_data:" << x._data << "_data2:" << x._data2 << endl;
}
