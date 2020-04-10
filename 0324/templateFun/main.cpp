#include <iostream>
using namespace std;

template <class T> T add(const T& lh, const T& rh);

template <class T> void testadd(const T& lh, const T& rh);

#define ADD(a,b) (a) + (b)

int main() {
    testadd(1, 4);
    //testadd(1, 4.0);

    cout << "ADD(1, 4.0):" << ADD(1, 4.0) << endl;

}

template <class T> void testadd(const T& lh, const T& rh) {
    cout << lh <<"+" << rh << "=" << add(lh, rh) << endl;
}
template <class T> T add(const T& lh, const T& rh) {
    return lh + rh;
}

