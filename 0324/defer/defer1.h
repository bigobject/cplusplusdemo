#pragma once

#include <functional>

#define CONNECTION(text1,text2) text1##text2
#define CONNECT(text1,text2) CONNECTION(text1,text2)

class DeferHelper {
 public:
    DeferHelper(std::function<void ()> &&cb) : cb_(std::move(cb)) {}
    ~DeferHelper() { if (cb_) cb_(); }
 private:
    std::function<void ()> cb_;
};
#define defer1(code)  DeferHelper CONNECT(L,__LINE__) ([&](){code;})
