#include <iostream>
#include <mutex>
#include<memory> 
#include<vector>

using vbool = std::vector<bool>;
using cvbool = const std::vector<bool>;

int main() {
    bool flag = false;
    vbool i = {false, false, true};
    auto iflag = i[2];

    int sts[10];

    flag = iflag;
    std::cout << flag << std::endl;

    cvbool ci = {false, false, true};
    auto ciflag = ci[2];
    flag = ciflag;
    std::cout << flag << std::endl;

    //auto& criflag = ci[2];
    //std::cout << criflag << std::endl;

    auto&& crriflag = ci[2];
    flag = crriflag;
    std::cout << flag << std::endl;
}
