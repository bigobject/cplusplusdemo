#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T, std::size_t N> 
constexpr std::size_t array_size(T (&) [N]) {
    return N;
};





int main() {
    int sss[] = {2,3,4,4,2};

    const int ssslen = array_size(sss);
    cout << ssslen << endl;
    
}


