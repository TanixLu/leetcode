#include <iostream>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
    const char m[16]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    
public:
    string toHex(int num) {
        if(num == 0)return string{'0'};
        unsigned n = (unsigned)num;
        string str;
        while(n != 0){
            unsigned r = n & 0b1111;
            str.insert(str.begin(), m[r]);
            n >>= 4;
        }
        return str;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.toHex(26);
}
