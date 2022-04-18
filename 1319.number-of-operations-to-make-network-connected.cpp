#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class DisjointSet{
    vector<int> p;

    void link(int x, int y){p[x] = y;}

public:
    DisjointSet(int n): p(n) {iota(p.begin(), p.end(), 0);}
    int find(int x){
        if(p[x] != x)p[x] = find(p[x]);
        return p[x];
    }
    void Union(int x, int y){link(find(x), find(y));} 
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() + 1 < n)return -1;
        DisjointSet ds(n);
        int area = n;
        for(auto& con: connections){
            if(ds.find(con[0]) != ds.find(con[1])){
                ds.Union(con[0], con[1]);
                area--;
            }
        }
        return area - 1;
    }
};
// @lc code=end

int main(){
    Solution s;
    // int n = 4; vector<vector<int>> cons{{0,1}, {0,2}, {1,2}};
    // int n = 6; vector<vector<int>> cons{{0,1}, {0,2}, {0,3}, {1,2}, {1,3}};
    int n = 6; vector<vector<int>> cons{{0,1}, {0,2}, {0,3}, {1,2}};
    cout << s.makeConnected(n, cons);
}
