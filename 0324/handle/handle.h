#ifndef _HANDLE_
#define _HANDLE_

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

    bool reattach(Count& rhs) {
        ++*rhs.num;
        if (0 == --*num) {
            delete num;
            num = rhs.num;
            return true;
        }

        num = rhs.num;
        return false;
    }

    bool only() {return 1 == *num;};

    bool makeOnly() {
        if (1 == *num)
            return false;
        --*num;
        num = new int;
        return true;
    }

    ~Count() {
        if (0 == --*num)
            delete num;
    };
    int* num;
};

class Data{
public:
    Data(int i, float f):m_i(i), m_f(f){};
    Data(Data& rhs):m_i(rhs.m_i), m_f(rhs.m_f){};
    void Seti(int i) {m_i = i;};

friend std::ostream& operator<< (std::ostream& os, const Data& data);
private:
    int m_i;
    float m_f;
};

class Handle {
public:
    Handle(int i, float f):m_pdata(new Data{i, f}){};
    Handle(Handle& rhs):m_pdata(rhs.m_pdata), count(rhs.count) {};

    Handle& operator= (Handle& rhs) {
        if (count.reattach(rhs.count))
            delete m_pdata;
        m_pdata = rhs.m_pdata;
        return *this;
    }

    Data * operator-> () {
        if (count.makeOnly()) {
            m_pdata = new Data(*m_pdata);
        }
        return m_pdata;
    }
    
    ~Handle() {
        if (count.only()) {
            delete m_pdata;
        }
    }

friend std::ostream& operator<< (std::ostream& os, const Handle& handle);
private:
    Data * m_pdata;
    Count count;
};

std::ostream& operator<< (std::ostream& os, const Data& data) {
    return os << "m_i:" << data.m_i << ", m_f:" << data.m_f;
}
std::ostream& operator<< (std::ostream& os, const Handle& handle) {
    if (nullptr != handle.m_pdata)
        os << *handle.m_pdata << std::endl;
    return os;
}
#endif