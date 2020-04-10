#include <iostream>
#include <mutex>
#include<memory> 

using namespace std;

class Duration;
class people{
public:
    people(string _name): m_name(_name) {};
    void love(people& loved, Duration& dura) {
        std::cout << m_name << std::string(" loving ") << loved.name();
        std::cout << dura << std::endl;
    };
    std::string name() {return m_name;};
private:
    std::string m_name;
};
people cc("cc"), gl("gl");

class Duration {
public:
    Duration(std::string value, std::string unit): m_value(value), m_unit(unit) {};
    friend std::ostream& operator<<(std::ostream&out, Duration& dura);
    friend std::ostream& operator<<(std::ostream&out, Duration&& dura);
private:
    std::string m_value;
    std::string m_unit;
};

std::ostream& operator<< (std::ostream& out, Duration& dura)
{
    return out << std::move(dura);
}
std::ostream& operator<< (std::ostream& out, Duration&& dura)
{
    return out << dura.m_value << " " << dura.m_unit;
}

int main() {
    Duration dura("10000", "year");
    std::cout << dura;
    cc.love(gl, dura);
}
