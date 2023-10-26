// Vector test
#include "Vector.h"
#include "my_tools.h"
#include <iostream>

using namespace std;
using namespace slib;


void test()
{
    Vector<int> a;

    Vector<int> first;                   // empty vector of ints
    check(first.size() == 0);
    check(first.empty() == true);
    Vector<int> second(4, 100);                       // four ints with value 100
    check(second.empty() == false);
    check(second.size() == 4);
    check(*second.begin() == 100);
    Vector<int> fourth(second);                       // a copy of third
    check(fourth.size() == second.size());
    check(fourth[0] == 100);
    check(fourth[1] == 100);
    check(fourth[2] == 100);
    check(fourth[3] == 100);

    int myints[] = { 16,2,77,29 };
    Vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    check(fifth.empty() == false);
    check(fifth[0] == 16);
    check(fifth[3] == 29);
    check(fifth.size() == sizeof(myints) / sizeof(int));
    print(fifth, "fifth");//The contents of fifth are:16 2 77 29
    fifth.push_back(30);
    check(fifth[4] == 30);
    check(fifth.size() == 5);
    print(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    check(fifth.size() == sizeof(myints) / sizeof(int) + 1);
    first = fifth = fifth;
    print(first, "first");//The contents of first are:16 2 77 29 30
    check(first.empty() == false && first.size() == fifth.size());
    print_itr(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    print_const_itr(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    std::sort(fifth.begin(), fifth.end());
    {
    Vector<int> t{ 2, 16, 29, 30, 77 };
    check(fifth == t);
    }
    std::cout << "fifith after sort:" << std::endl;
    print_const_itr(fifth, "fifth");//The contents of fifth are:16 2 77 29 30
    Vector<int> a1(myints, myints + sizeof(myints) / sizeof(int));
    {
    Vector<int> b(a1);
    b.push_back(2);
    check(b[4] == 2);
    auto result = (b == Vector<int>{ 16, 2, 77, 29, 2});
    check(result);

    //iterator
    {
    check(b.begin() + b.size() == b.end());
    auto begin = b.begin();
    auto itr = b.begin() + 1;
    check(*begin == 16);
    check(*itr == 2);
    }
    //const iterator
    {
    check(b.cbegin() + b.size() == b.cend());
    auto begin = b.cbegin();
    auto itr = b.cbegin() + 1;
    check(*begin == 16);
    check(*itr == 2);
    check(++begin == itr);
    }
    {
    Vector<long> aa;
    check(aa.begin() == aa.end());
    check(aa.cbegin() == aa.cend());
    }
    }
    {
    Vector<int> b{ 1,3,5,7 };
    b.push_back(9);
    }
    {
    Vector<int> c;
    for (auto i : c) { std::cout << i << " "; }
    c = a1;
    for (auto i : c) { std::cout << i << " "; }
    std::cout << std::endl;
    }
    check(a1.size() == sizeof(myints) / sizeof(int));
    {
    Vector<int> c;
    c = fifth;
    c[0] = 1;
    check(c[0] == 1);
    }
    {
    Vector<int> aa{ 1, 2, 3 };
    Vector<int> b{ 1, 2, 3, 4 };
    check(aa != b);
    auto c = b;
    c.push_back(5);
    check(c != b);
    c = b;
    check(c == b);
    }
    //test char
    {
    Vector<char> arr(10, 'a');
    char buffer[10] = { 0 };
    int index = 0;
    for (auto& c : arr)
    {
        buffer[index++] = c;
    }
    check(index == 10);
    for (int j = 0; j < 10; j++)
    {
        assert(buffer[j] == arr[j]);
        assert(buffer[j] == 'a');
    }
    }
    test_vector_vector();
    {
        Vector<int> arr1{ 1,1,3 };
        Vector<int> arr2{ 2,2,3 };
        check(arr1 != arr2);
        Vector<int> arr3{ 2,2,3 };
        check(arr2 == arr3);
        Vector<int> arr4{ 2,2,3, 3 };
        check(arr3 != arr4);
        check(arr4 != arr3);
    }
}