#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

/*
 * @lc app=leetcode id=805 lang=cpp
 *
 * [805] Split Array With Same Average
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), s = accumulate(nums.begin(), nums.end(), 0);

        if(s == 0 && n >= 2)return true;

        vector<unsigned> dp(s / 2 + 1, 0);  // dp[i][j]表示j个数是否能和为i
        dp[0] = 0b1;
        for(auto num: nums){  // 对num在线
            for(int i = s / 2; i >= num; i--){
                dp[i] |= dp[i - num] << 1;
            }
        }
        for(int j = 1; j <= n / 2; j++)
            if(j * s % n == 0 && ((dp[j * s / n] >> j) & 0b1))
                return true;
        return false;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums{1,2,3,4,5,6,7,8};
    cout << s.splitArraySameAverage(nums);
}
