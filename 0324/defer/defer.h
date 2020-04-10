#ifndef _DEFER_
#define _DEFER_

#include <functional>#include <iostream>

class deferHelper {
public:
    deferHelper(std::function<void()>&& fun):m_fun(std::move(fun)) {};
    ~deferHelper() {
        std::cout<< "deferHelper" << std::endl;
        m_fun();};
private:
    std::function<void()> m_fun;
};

#define DEFER0_2(text1, text2) text1##text2
#define DEFER0_1(text1, text2) DEFER0_2(text1, text2)

#define defer(code) auto DEFER0_1(L, __LINE__) = deferHelper([&]{code;})
#endif
