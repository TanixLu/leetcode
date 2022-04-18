#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
    const int table[9] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};

public:
    int countNumbersWithUniqueDigits(int n) {
        // int ans = 1, A = 9;
        // for(int i = 0; i < n; i++){
        //     ans += A;
        //     A *= 9 - i;
        // }
        // return ans;
        return table[n];
    }
};
// @lc code=end

int main(){
    Solution s;
    for(int i = 0; i <= 8; i++)cout << s.countNumbersWithUniqueDigits(i) << '\n';
}
