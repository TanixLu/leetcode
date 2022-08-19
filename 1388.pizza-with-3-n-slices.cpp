#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=1388 lang=cpp
 *
 * [1388] Pizza With 3n Slices
 */

// @lc code=start
class Solution{
public:
    int maxSizeSlices(vector<int>& slices){
        const int n = slices.size() / 3;
        // 方法一: 动态规划, O(n^2)
        // return max<int>(maxVector(slices, 0, 3 * n - 2, n), maxVector(slices, 1, 3 * n - 1, n));

        // 方法二: 选择后将两侧合并, 可用优先队列改进到O(nlogn)
        list<int> l(slices.begin(), slices.end());
        int res = 0;
        for(int i = 0; i < n; i++){
            auto max_it = max_element(l.begin(), l.end());
            res += *max_it;
            *max_it = -*max_it;
            if(max_it == l.begin()){
                *max_it += l.back();
                l.pop_back();
            }
            else{
                *max_it += *next(max_it, -1);
                l.erase(next(max_it, -1));
            }
            if(next(max_it) == l.end()){
                *max_it += l.front();
                l.pop_front();
            }
            else{
                *max_it += *next(max_it);
                l.erase(next(max_it));
            }
        }
        return res;
    }

    int maxVector(vector<int>& a, int start, int end, int n){
        const int len = end - start + 1;
        vector<vector<int>> dp(len, vector<int>(n));
        dp[0][0] = a[start];
        for(int i = 1; i <= len - 2 * n + 1; i++) dp[i][0] = max<int>(dp[i - 1][0], a[start + i]);
        for(int j = 1; j <= n - 1; j++) dp[2 * j][j] = dp[2 * j - 2][j - 1] + a[start + 2 * j];
        for(int j = 1; j <= n - 1; j++)
            for(int i = 2 * j + 1; i <= len - 2 * n + 1 + 2 * j; i++)
                dp[i][j] = max<int>(dp[i - 1][j], dp[i - 2][j - 1] + a[start + i]);
        return dp[len - 1][n - 1];
    }

};
// @lc code=end

int main(){
    Solution s;
    vector<int> a{1,2,3,4,5,6};
    cout << s.maxSizeSlices(a);
}

