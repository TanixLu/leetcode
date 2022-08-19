#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int threshold = *max_element(candies.begin(), candies.end()) - extraCandies;
        vector<bool> res(candies.size());
        for(int i = 0; i < candies.size(); i++)
            res[i] = candies[i] >= threshold;
        return res;
    }
};
// @lc code=end

