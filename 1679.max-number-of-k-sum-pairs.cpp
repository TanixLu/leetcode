#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0;
        for(auto n: nums){
            if(count[k - n] > 0){
                count[k - n]--;
                ans++;
            }
            else count[n]++;
        }   
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums{3,1,3,4,3};
    int k = 6;
    cout << s.maxOperations(nums, k);
}
