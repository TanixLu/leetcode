#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
class Solution {
public:
    inline int dis2(vector<int>& p1, vector<int>& p2){
        return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(auto& p1: points){
            unordered_map<int, vector<pair<int, int>>> m;
            for(auto& p2: points)
                m[dis2(p1, p2)].emplace_back(pair{p2[0], p2[1]});
            for(auto& vec: m)
                ans += vec.second.size() * (vec.second.size() - 1);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<vector<int>> points{{0,0}, {1,0}, {2,0}};
    // vector<vector<int>> points{{1,1}, {2,2}, {3,3}};
    vector<vector<int>> points{{1,1}};
    cout << s.numberOfBoomerangs(points);
}
