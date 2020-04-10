#include <iostream>
using namespace std;


template <class T>
class TClass
{
public:
    bool Equal(const T& arg, const T& arg1);
};

template <class T>
bool TClass<T>::Equal(const T& arg, const T& arg1)
{
    return (arg == arg1);
}

int main()
{    
    TClass<int> obj;
    cout<<obj.Equal(2, 2)<<endl;
    cout<<obj.Equal(2, 4)<<endl;
    TClass<float> objf;
    cout<<objf.Equal(2.32323, 2.32323)<<endl;
    cout<<objf.Equal(2.32323, 2.12323)<<endl;
}
