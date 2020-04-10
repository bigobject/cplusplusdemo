#include <iostream>
using namespace std;



template <typename T> 
class myclass {
public:
    myclass(const T& rhs): _value(rhs) {};
    const T GetValue() {return _value;};

    void SetValue(const T& rhs) {_value = rhs;};

    template <typename U> 
    friend ostream& operator<< (ostream&out, myclass<U>& obj);
private:
    T _value;
};

template <typename U> 
ostream& operator<< (ostream&out, myclass<U>& obj)
{
    return out << obj._value;
}

class wedget {
public:
    wedget(){};
    wedget(string name, int num): m_name(name), m_wedget(num){};
    friend ostream& operator<< (ostream&out, wedget& obj);

    virtual ~wedget(){};
private:
    string m_name;
    int m_wedget;
    
};

ostream& operator<< (ostream&out, wedget& obj)
{
    return out << "name:" << obj.m_name << ", wedget" << obj.m_wedget << endl;
}


int main() {
    myclass<int> intobj(3);
    cout << intobj << endl;
    intobj.SetValue(2);
    cout << intobj << endl;

    myclass<wedget> wdgobj(wedget(string("changchun"), 33600));
    cout << wdgobj << endl;
    wdgobj.SetValue(wedget(string("gaolei"), 33600));
    cout << wdgobj << endl;
    
}


