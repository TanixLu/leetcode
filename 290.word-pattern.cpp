#include <iostream>
#include <string>
#include <array>
#include <unordered_set>
using namespace std;

/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        array<string, 26> ss;
        unordered_set<string> known_str;
        int si = 0;
        for(int pi = 0; pi < pattern.size(); pi++){
            string temp;
            while(si < s.size() && s[si] != ' ')temp += s[si++];
            si++;
            if(temp.empty())return false;
            int ssi = pattern[pi] - 'a';
            if(ss[ssi].empty()){
                if(known_str.find(temp) == known_str.end()){
                    ss[ssi] = temp;
                    known_str.emplace(temp);
                }
                else return false;
            }
            else if(ss[ssi] != temp)return false;
        }
        if(si < s.size())return false;
        else return true;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.wordPattern("aabbb", "dog dog cat cat");
}
