#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 */

// @lc code=start
class Solution {
    vector<int> rem;
    vector<vector<int>> edges;
    vector<int> nums;
    int _n, m;
    
    bool isSquare(int n){
        if(n < 0)return false;
        int r{(int)round(sqrt(n))};
        return n == r * r;
    }

    int findPath(int i){
        int res = 0;
        
        ++m;
        rem[i]--;

        if(m == _n) res += 1;
        else{
            for(auto j: edges[i]){
                if(rem[j] == 0)continue;
                else res += findPath(j);
            }
        }

        --m;
        rem[i]++;

        return res;
    }
    
public:
    int numSquarefulPerms(vector<int>& _nums) {
        _n = _nums.size();
        sort(_nums.begin(), _nums.end());
        int pre = -1;
        nums.clear();
        rem.clear();
        for(auto num: _nums){
            if(num != pre){
                nums.emplace_back(num);
                rem.emplace_back(1);
                pre = num;
            }
            else rem.back()++;
        }
        int n = nums.size();

        edges.resize(n, vector<int>{});
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isSquare(nums[i] + nums[j]))
                    edges[i].emplace_back(j);

        m = 0;
        int res = 0;
        for(int i = 0; i < n; i++)
            res += findPath(i);
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<int> nums{1,17,8};
    vector<int> nums{2,2,2};
    // vector<int> nums{1,1};
    cout << s.numSquarefulPerms(nums);
}
