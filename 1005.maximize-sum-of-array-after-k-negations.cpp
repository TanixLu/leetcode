#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && k > 0 && nums[i] < 0; i++, k--)
            nums[i] = -nums[i];
        return accumulate(nums.begin(), nums.end(), 0) - (k % 2) * *min_element(nums.begin(), nums.end()) * 2;
    }
};
// @lc code=end

// int main(){
//     Solution s;
//     vector<int> nums = {-4, -2, -3};
//     int k = 2;
//     cout << s.largestSumAfterKNegations(nums, k);
// }
