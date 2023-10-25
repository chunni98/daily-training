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
    check(v2.capacity() == 20);
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

    Vector v9;
    for (size_t i = 0; i < 10; i++) {
        v9.push_back(i);
    }
    check(v9.size() == 10);
    check(v9.capacity() == 20);
    cout << "=====================" << endl;
    Vector::Iterator iter = v9.begin();
    check(*iter == 0);

    for (; iter != v9.end(); ++iter) {
        cout << *iter << endl;
    }

}

void test2()
{
    Vector a;

    Vector first;                   // empty vector of ints
    check(first.empty() == true && first.size() == 0);
    Vector second(4, 100);                       // four ints with value 100
    check(second.empty() == false);
    check(second.size() == 4);
    check(*second.begin() == 100);
    Vector fourth(second);                       // a copy of third
    check(fourth.size() == second.size());

    int myints[] = { 16,2,77,29 };
    Vector fifth(myints, myints + sizeof(myints) / sizeof(int));
    check(fifth.empty() == false);
    check(fifth[0] == 16);
    check(fifth[3] == 29);
    check(fifth.size() == sizeof(myints) / sizeof(int));
    //print(fifth, "fifth");//The contents of fifth are:16 2 77 29
    fifth.push_back(30);
    check(fifth[4] == 30);
    check(fifth.size() == 5);
    //print(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    check(fifth.size() == sizeof(myints) / sizeof(int) + 1);
    first = fifth = fifth;
    //print(first, "first");//The contents of first are:16 2 77 29 30
    check(first.empty() == false && first.size() == fifth.size());
    //print_itr(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    //print_const_itr(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    Vector a1(myints, myints + sizeof(myints) / sizeof(int));
    {
        Vector b(a1);
        b.push_back(2);
        check(b[4] == 2);
    }
    {
        Vector c;
        for (auto i : c)
        {
            std::cout << i << " ";
        }
        c = a1;
        a1 = c;
        c = a1;

        for (auto i : c)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    check(a1.size() == sizeof(myints) / sizeof(int));
    {
        Vector c;
        c = fifth;
        c[0] = 1;
        check(c[0] == 1);
    }
}