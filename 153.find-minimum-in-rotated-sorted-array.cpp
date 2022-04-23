#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] > nums[r])l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> numss{
        {3,4,5,1,2},
        {4,5,6,7,0,1,2},
        {11,13,15,17},
    };
    for(auto& nums: numss)
        cout << s.findMin(nums) << ' ' << *min_element(nums.begin(), nums.end()) << '\n';
}
