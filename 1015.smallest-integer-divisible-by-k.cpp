#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0;
        for(int i = 1; i <= k; i++){
            rem = rem * 10 + 1;
            while(rem >= k)rem -= k;
            if(rem == 0)return i;
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.smallestRepunitDivByK(3);
}
