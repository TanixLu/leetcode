#include <string>
#include <array>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        array<int, 26> l, r;
        int maxlen = -1;
        l.fill(-1);
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(l[c] == -1)l[c] = i;
            r[c] = i;
            maxlen = max<int>(maxlen, r[c] - l[c] - 1);
        }
        return maxlen;
    }
};
// @lc code=end

