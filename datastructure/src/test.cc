// Vector test
#include "Vector.h"
#include "my_tools.h"
#include <iostream>

using namespace std;
using namespace slib;

void vector_test()
{
    Vector v1;
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(4);
    check(v1.size() == 3);
    check(v1.capacity() == 5);
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << v1[i] << ' ';
    }
    cout << endl;
    v1.clear();
    check(v1.size() == 0);
    check(v1.capacity() == 0);

    cout << "=======" << endl;

    Vector v2(10);
    check(v2.size() == 10);
    check(v2.capacity() == 10);
    Vector v3(11);
    check(v3.size() == 11);
    check(v3.capacity() == 20);
    cout << v3.capacity() << endl;

    Vector v4;
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(3);
    v4.push_back(4);
    v4.push_back(5);
    v4.push_back(6);
    v4.push_back(7);
    v4.push_back(8);
    v4.push_back(9);
    v4.push_back(10);
    v4.push_back(11);
    v4.push_back(12);
    check(v4.empty() == false);
    check(v4.size() == 12);
    check(v4.capacity() == 20);

    for (size_t i = 0; i < v4.size(); ++i) {
        cout << v4[i] << ' ';
    }
    cout << endl;

    Vector v5;
    check(v5.empty() == true);
    check(v5.size() == 0);

    Vector v6(v4);
    check(v6.empty() == false);
    check(v6.size() == 12);
    check(v6.capacity() == 20);
    Vector v7 = v4;
    check(v7.empty() == false);
    check(v7.size() == 12);
    check(v7.capacity() == 20);

    Vector v8;
    v7 = v8;
    check(v7.empty() == true && v7.size() == 0);
}