#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)return nums.size();
        int place = 2;
        for(int i = 2; i < nums.size(); i++)
            if(nums[i] != nums[place - 2])
                nums[place++] = nums[i];
        return place;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> numss{
        {1,1,1,2,2,3},//1 1 2 2 3
        {0,0,1,1,1,1,2,3,3}//0 0 1 1 2 3 3
    };
    for(auto& nums: numss){
        int k = s.removeDuplicates(nums);
        for(int i = 0; i < k; i++)cout << nums[i] << ' ';
        cout << '\n';
    }
}
