#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> left_most_bolck_max_right(n, -1);
        for(int i = 0; i < n + 1; i++){
            int r = ranges[i];
            int start = max(0, i - r);
            int end = min(n - 1, i + r - 1);
            if(start <= end)left_most_bolck_max_right[start] = max(left_most_bolck_max_right[start], end);
        }
        int cur_place = 0, tap_num = 0;
        while(cur_place < n){
            int max_right = left_most_bolck_max_right[cur_place];
            if(max_right == n - 1)return tap_num + 1;
            else{
                int farthest_right = max_right;
                for(int i = cur_place + 1; i <= max_right + 1; i++){
                    if(left_most_bolck_max_right[i] > farthest_right){
                        cur_place = i;
                        farthest_right = left_most_bolck_max_right[i];
                    }
                }
                if(farthest_right == max_right)return -1;
                else tap_num++;
            }
        }
        return tap_num;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> rangess{
        {3,4,1,1,0,0},//1
        {0,0,0,0}//-1
    };
    for(auto& ranges: rangess)
        cout << s.minTaps(ranges.size() - 1, ranges) << '\n';
}
