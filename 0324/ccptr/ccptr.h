#ifndef _CCPTR_
#define _CCPTR_

#include <iostream>

class Count {
public:
    Count() {num = new int(1);};

    Count(Count&rhs) {
        ++rhs.num;
        num = rhs.num;
    };

    Count& operator= (Count& rhs) {
        ++*rhs.num;
        if (0 == --*num)
            delete num;
        num = rhs.num;
        return *this;
    }

    void reattach(Count& rhs) {
        ++*rhs.num;
        if (0 == --*num) {
            delete num;
        }

        num = rhs.num;
    }

    bool only() {return 1 == *num;};

    void makeOnly() {
        if (1 == *num)
            return ;
        --*num;
        num = new int;
        return;
    }

    ~Count() {
        if (0 == --*num)
            delete num;
    };
    int* num;
};

template <typename T>
class Ccptr {
public:
    template <typename... U>
    Ccptr(U... Args):m_pdata(new T(Args...)){};
    Ccptr(Ccptr& rhs):m_pdata(rhs.m_pdata), count(rhs.count) {};

    Ccptr& operator= (Ccptr& rhs) {
        if (count.only())
            delete m_pdata;

        count.reattach(rhs.count);
        m_pdata = rhs.m_pdata;
        return *this;
    }

    T* operator-> () {
        if (!count.only()) {
            m_pdata = new T(*m_pdata);
            count.makeOnly();
        }
        return m_pdata;
    }
    
    ~Ccptr() {
        if (count.only()) {
            delete m_pdata;
        }
    }

    template <class U>
    friend std::ostream& operator<< (std::ostream& os, const Ccptr<U>& ptr);

public:
    T * m_pdata;
    Count count;
};

template <class U>
std::ostream& operator<< (std::ostream& os, const Ccptr<U>& ptr) {
    if (nullptr != ptr.m_pdata)
        os << (const U)*ptr.m_pdata;
    return os;
}

class Data{
public:
    Data(int i, float f):m_i(i), m_f(f){
        std::cout<< "consturct Data" <<std::endl;
    };
    Data(Data& rhs):m_i(rhs.m_i), m_f(rhs.m_f){
        std::cout<< "copy consturct Data" <<std::endl;};
    void Seti(int i) {m_i = i;};

    ~Data() {
        std::cout<< "destory Data" <<std::endl;
    }

friend std::ostream& operator<< (std::ostream& os, const Data& data);
private:
    int m_i;
    float m_f;
};

std::ostream& operator<< (std::ostream& os, const Data& data) {
    return os << "m_i:" << data.m_i << ", m_f:" << data.m_f;
}
#endif