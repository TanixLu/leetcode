#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution {
    struct Point{
        int x, y;
        bool operator==(const Point& p) const {
            return (x == p.x) && (y == p.y);
        }
        bool operator<(const Point& r) const {
            if(x < r.x) return true;
            else if(x > r.x) return false;
            else return y < r.y;
        }
    };

    int comp(const Point& p1, const Point& p2, const Point& p3){
        return (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), [](const vector<int>& t1, const vector<int>& t2){
            if(t1[0] < t2[0]) return true;
            else if(t1[0] > t2[0]) return false;
            else return t1[1] <t2[1];
        });

        vector<Point> l, u;
        int n;
        for(auto& tree: trees){
            Point p{tree[0], tree[1]};
            while((n = l.size()) >= 2 && comp(l[n - 2], l[n - 1], p) > 0) l.pop_back();
            while((n = u.size()) >= 2 && comp(u[n - 2], u[n - 1], p) < 0) u.pop_back();
            l.emplace_back(p);
            u.emplace_back(p);
        }

        set<Point> temp(l.begin(), l.end());
        for(auto& p: u) temp.emplace(p);

        vector<vector<int>> res;
        for(auto& p: temp) res.emplace_back(vector<int>{p.x, p.y});

        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> trees = {
        {1, 1}, {2, 2}, {2, 0},
        {2, 4}, {3, 3}, {4, 2}
    };
    s.outerTrees(trees);
}
