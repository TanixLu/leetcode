#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min(unordered_set(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> vec{6,6,6,6};
    cout << s.distributeCandies(vec);
}
