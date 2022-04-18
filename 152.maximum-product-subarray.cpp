#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        for(int i = 1, imax = r, imin = r; i < nums.size(); i++){
            int candidates[]{nums[i], nums[i] * imax, nums[i] * imin};
            imax = *max_element(begin(candidates), end(candidates));
            imin = *min_element(begin(candidates), end(candidates));
            r = max(r, imax);
        }
        return r;
    }
};
// @lc code=end

