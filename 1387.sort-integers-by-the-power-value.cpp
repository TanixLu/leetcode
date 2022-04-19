#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
class Solution {
    int power[1001];

    int get_power(int n){
        if(n < 2)return 0;
        else if(n & 1)return get_power(n * 3 + 1) + 1;
        else return get_power(n / 2) + 1;
    }
    
public:
    int getKth(int lo, int hi, int k) {
        for(int i = 1; i <= 1000; i++)power[i] = get_power(i);
        
        vector<int> vec(hi - lo + 1);
        iota(vec.begin(), vec.end(), lo);
        
        nth_element(begin(vec), begin(vec) + k - 1, end(vec), [&](int a, int b){
            if(power[a] == power[b])return a < b;
            else return power[a] < power[b];
        });
        
        return vec[k - 1];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> los{12, 7};
    vector<int> his{15, 11};
    vector<int> ks{2,4};
    for(int i = 0; i < los.size(); i++)
        cout << s.getKth(los[i], his[i], ks[i]) << '\n';
    return 0;
}
