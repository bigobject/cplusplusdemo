#include <iostream>
#include<vector> 
#include<iterator>
#include<algorithm>

int main() {
    std::vector<std::string> input{"sdfs", "sdfwef", "23sds"};

    sort(input.begin(), input.end(), std::greater<std::string>());
    copy(input.begin(), input.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
