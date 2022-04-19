#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)return 1;
        vector<int> degree(n + 1, 0), possible;
        for(auto& t: trust){
            degree[t.front()]--;
            degree[t.back()]++;
            if(degree[t.back()] == n - 1)possible.emplace_back(t.back());
        }
        if(possible.size() == 1 && degree[possible.front()] == n - 1)return possible.front();
        else return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<vector<int>>> trusts{
        {{1,2}},
        {{1,3}, {2,3}},
        {{1,3}, {2,3}, {3,1}},
        {}
    };
    vector<int> ns{
        2,
        3,
        3,
        1
    };
    for(int i = 0; i < trusts.size(); i++)
        cout << s.findJudge(ns[i], trusts[i]) << '\n';
    return 0;
}
