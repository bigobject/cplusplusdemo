#ifndef _CCPTR_
#define _CCPTR_

#include <iostream>

class Data{
public:
    Data(char c):m_c(c){
        std::cout<< "consturct Data : " << c <<std::endl;
    };

    ~Data() {
        std::cout<< "destory Data : " << m_c <<std::endl;
    }
private :
    char m_c;
};

#endif