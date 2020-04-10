#include <iostream>
//#include<atomic>
using namespace std;

//std::atomic<int> i = 0;

class wedge {
public:
    wedge(const wedge&r):m_i(r.m_i){
        std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << "i:" << m_i<<std::endl;
    };
    wedge(const int i):m_i(i){
        std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << "i:" << m_i<<std::endl;
    };
    int m_i;
};

class dwedge :public wedge {
    public:
    dwedge(const int i):wedge(i){};
};
int main() {
    wedge t = 0;
    std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << "t:" << t.m_i<<std::endl;

    dwedge dt = 0;
    std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << "dt:" << dt.m_i<<std::endl;

    //std::cout << __FILE__<< "|" << __FUNCTION__ << "|" << __LINE__ << "t:" << i<<std::endl;

}
