#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned temp = n ^ (n >> 1);
        return (temp & (temp + 1)) == 0;
    }
};
// @lc code=end

int main(){
    Solution s;
    int a[]{5, 7, 11};
    for(int i = 0; i < 3; i++)
        cout << s.hasAlternatingBits(a[i]) << '\n';
}
