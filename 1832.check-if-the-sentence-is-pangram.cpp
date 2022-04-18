#include <string>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool a[26]{};
        int count = 0;
        for(auto c: sentence){
            if(a[c - 'a'] == false){
                a[c - 'a'] = true;
                count++;
                if(count == 26)return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main(){
    Solution s;
    string str{"leetcode"};
    cout << s.checkIfPangram(str);
}
