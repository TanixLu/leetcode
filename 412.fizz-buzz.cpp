#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r(n);
        for(int i = 1; i <= n; i++)r[i - 1] = to_string(i);
        for(int i = 3; i <= n; i += 3)r[i - 1] = "Fizz";
        for(int i = 5; i <= n; i += 5)r[i - 1] = "Buzz";
        for(int i = 15; i <= n; i += 15)r[i - 1] = "FizzBuzz";
        return r;
    }
};
// @lc code=end

int main(){
    Solution s;
    for(auto str: s.fizzBuzz(15))cout << str << '\n';
}
