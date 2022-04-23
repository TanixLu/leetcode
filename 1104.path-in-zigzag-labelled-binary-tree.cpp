#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 */

// @lc code=start
class Solution {
    int msb(unsigned x) {
        union { double a; int b[2]; };
        a = x;
        return (b[1] >> 20) - 1023;
    }
    
public:
    vector<int> pathInZigZagTree(int label) {
        int n = msb(label);
        vector<int> res(n + 1);
        res.back() = label;
        for(int i = n - 1; i >= 0; i--){
            label = (label >> 1) ^ ((1 << i) - 1);
            res[i] = label;
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> vec = s.pathInZigZagTree(26);
    for(auto e: vec)cout << e << ' ';
}
