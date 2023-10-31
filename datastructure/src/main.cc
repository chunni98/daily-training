#include <iostream>
#include "Vector.hpp"


using namespace std;
using namespace slib;

int main(int argc, const char *argv[])
{
    Vector<int> vec{1, 3};
    cout << vec << endl;
    Vector<int> vec2{5, 2};
    cout << vec2 << endl;

    cout << "Hello, World!\n";

    return 0;
}