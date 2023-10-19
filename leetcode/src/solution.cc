#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include "Solution.h"

using namespace std;

#ifdef leetcode14
string Solution::longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) {
        return "";
    }
    size_t index = 0;

    for (size_t i = 0; i < strs[0].size(); ++i) {
        for (size_t j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                goto end;
            }
        }
            index++;
    }
end:
    return {strs[0], 0, index};
}

// leetcode14 官方题解
// string longestCommonPrefix(vector<string>& strs) {
//     if (!strs.size()) {
//         return "";
//     }
//     int length = strs[0].size();
//     int count = strs.size();
//     for (int i = 0; i < length; ++i) {
//         char c = strs[0][i];
//         for (int j = 1; j < count; ++j) {
//             if (i == strs[j].size() || strs[j][i] != c) {
//                 return strs[0].substr(0, i);
//             }
//         }
//     }
//     return strs[0];
// }
#endif //leetcode14