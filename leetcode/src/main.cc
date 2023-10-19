#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include "solution.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Solution s;
#ifdef leetcode14
    vector<string> vecs {"flow","flowe","fl"};
    cout << quoted(s.longestCommonPrefix(vecs)) << endl;
#endif // leetcode14
    return 0;
}