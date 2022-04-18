#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return (n & 0b11) != 0;
    }
};
// @lc code=end

int main(){
    cout << (2 & 0b11);
}

