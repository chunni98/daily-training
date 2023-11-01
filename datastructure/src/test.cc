#include "Vector.hpp"
#include "my_tools.h"
#include <cassert>

using namespace slib;
using namespace std;

void test1(void)
{
    Vector<int> v;
    check(v.size() == 0);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    check(v.size() == 10);
    for (int i = 0; i < 10; i++)
    {
        check(v[i] == i);
    }
    check(v.size() == 10);
}
void test2(void)
{
    int n = 100000;
    Vector<int> v;
    check(v.size() == 0);
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        assert(v[i] == i);//这里必须用assert，否则会疯狂打印pass
    }
    check(v.size() == n);
}

void test3()
{
    Vector<int> a;

    Vector<int> first;                   // empty vector of ints
    check(first.empty() == true && first.size() == 0);
    Vector<int> second(4, 100);                       // four ints with value 100
    check(second.empty() == false);
    check(second.size() == 4);
    Vector<int> fourth(second);                       // a copy of third
    check(fourth.size() == second.size());

    int myints[] = { 16,2,77,29 };
    Vector<int> fifth;
    fifth.push_back(16);
    fifth.push_back(2);
    fifth.push_back(77);
    fifth.push_back(29);

    check(fifth.empty() == false);
    check(fifth[0] == 16);
    check(fifth[3] == 29);
    check(fifth.size() == sizeof(myints) / sizeof(int));
    fifth.push_back(30);
    check(fifth[4] == 30);
    check(fifth.size() == 5);
    check(fifth.size() == sizeof(myints) / sizeof(int) + 1);
    first = fifth = fifth;
    check(first.empty() == false && first.size() == fifth.size());

    Vector<int> a1;
    a1.push_back(16);
    a1.push_back(2);
    a1.push_back(77);
    a1.push_back(29);
    {
        Vector<int> b(a1);
        b.push_back(2);
        check(b[4] == 2);
        check(b[0] == 16);
    }
    {
        Vector<int> c;
        c = a1;
        std::cout << std::endl;
    }
    check(a1.size() == sizeof(myints) / sizeof(int));
    {
        Vector<int> c;
        c = fifth;
        c[0] = 1;
        check(c[0] == 1);
    }
}

void test4()
{
    Vector<int> vec{3,1};
    // 迭代器使用
    for (const auto &val : vec)
    {
        cout << val << endl;
    }
    for (auto &val : vec)
    {
        val = 3;
    }
    for (const auto &val : vec)
    {
        cout << val << endl;
    }

}