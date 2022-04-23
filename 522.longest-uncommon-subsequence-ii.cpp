#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
class Solution {
    vector<string> longer_strs;
    bool isSubseq(const string& a, const string& b){
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j])(i++, j++);
            else j++;
        }
        if(i == a.size())return true;
        else return false;
    }
    bool isSubseqLonggerStrs(const string& a){
        for(auto& b: longer_strs)if(isSubseq(a, b))return true;
        return false;
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        map<int, unordered_map<string, int>> len_string_num;
        for(auto& str: strs)len_string_num[str.size()][str]++;
        for(auto rit = len_string_num.rbegin(); rit != len_string_num.rend(); rit++){
            for(auto& str_num: rit->second){
                if(isSubseqLonggerStrs(str_num.first))continue;
                if(str_num.second == 1)return rit->first;
                longer_strs.emplace_back(str_num.first);
            }
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<string>> strss{
        {"aba", "cdc", "eae"},//3
        {"aaa", "aaa", "aa"}//-1
    };
    for(auto& strs: strss)
        cout << s.findLUSlength(strs) << '\n';
}
