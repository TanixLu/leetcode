#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size() - 1; i++){
            int dx = abs(points[i][0] - points[i + 1][0]);
            int dy = abs(points[i][1] - points[i + 1][1]);
            res += max(dx, dy);
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<vector<int>>> pointss{
        {{1,1}, {3,4}, {-1,0}},//7
        {{3,2}, {-2,2}}//5
    };
    for(auto& points: pointss)
        cout << s.minTimeToVisitAllPoints(points) << '\n';
}
