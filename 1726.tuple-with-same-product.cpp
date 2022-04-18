#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 */

// @lc code=start

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                res += 8 * m[nums[i] * nums[j]]++;
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<int> nums{2,3,4,6};
    vector<int> nums{1,2,4,5,10};
    cout << s.tupleSameProduct(nums);
}
