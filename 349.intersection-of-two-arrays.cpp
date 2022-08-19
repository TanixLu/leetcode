#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bucket(1001, 0);
        for(auto num: nums1)bucket[num] = 1;
        for(auto num: nums2)if(bucket[num] == 1)bucket[num] = 2;
        vector<int> res;
        for(int num = 0; num <= 1000; num++)if(bucket[num] == 2)res.emplace_back(num);
        return res;
    }
};
// @lc code=end

