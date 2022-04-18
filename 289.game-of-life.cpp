#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int m = b.size(), n = b[0].size();
        vector<vector<int>> nb(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                for(auto& dir: dirs)
                    if(i + dir.first >= 0 && i + dir.first < m && j + dir.second >= 0 && j + dir.second < n && b[i + dir.first][j + dir.second] == 1)
                        nb[i][j]++;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(b[i][j] == 1){
                    if((nb[i][j] < 2 || nb[i][j] > 3))b[i][j] = 0;
                }
                else if(nb[i][j] == 3)b[i][j] = 1;
            }
        }
    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<vector<int>> b{{1,1}, {1,0}};
    vector<vector<int>> b{{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    s.gameOfLife(b);
    for(auto& vec: b){
        for(auto v: vec)cout << v << ' ';
        cout << '\n';
    }
}
