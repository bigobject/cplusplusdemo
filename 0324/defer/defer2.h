#pragma once

#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_0(x)    DEFER_2(x, __COUNTER__)
#define defer2(expr)   auto DEFER_0(_defered_option) = deferer([&](){expr;})

template <typename Function>
struct doDefer {
    Function f;
    doDefer(Function f) : f(f) {}
    ~doDefer() { f(); }
};

template <typename Function>
doDefer<Function> deferer(Function f) {
    return doDefer<Function>(f);
};
