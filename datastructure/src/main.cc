#include "my_tools.h"
#include "Vector.h"

using namespace slib;

int main(int argc, const char *argv[])
{
    Vector vec;
    vec.clear();
    check(vec.size() == 0);
    check(vec.capacity() == 0);
    check(vec.empty() == true);
    Vector v2(10);
    check(v2.size() == 10);
    check(v2.capacity() == 10);
    check(v2.empty() == false);

    Vector v3(v2);
    check(v3.size() == 10);
    check(v3.capacity() == 10);
    check(v3.empty() == false);

    return 0;
}