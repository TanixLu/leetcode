#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
template<typename T>
class DequeK{
    int k, start = 0, end = 0;
    vector<T> a;
    
public:
    DequeK(int k): k(k), a(k + 1) {}
    bool empty() {return start == end;}
    T front() {return a[start];}
    void push_front(T val) {a[start--] = val; if(start < 0)start = k;}
    void pop_front() {++start; if(start > k)start = 0;}
    T back() {return (end == 0)? a[k]: a[end - 1];}
    void push_back(T val) {a[end++] = val; if(end > k)end = 0;}
    void pop_back() {--end; if(end < 0)end = k;}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 优先队列O(nlogn)
        // const int n = nums.size();
        // vector<int> res(n - k + 1);
        // multiset<int> aux(nums.begin(), next(nums.begin(), k));
        // res[0] = *aux.rbegin();
        // for(int i = k; i < n; i++){
        //     aux.erase(aux.find(nums[i - k]));
        //     aux.emplace(nums[i]);
        //     res[i - k + 1] = *aux.rbegin();
        // }
        // return res;

        // 利用先进先出性质O(n)
        
        const int n = nums.size();
        DequeK<int> dq(k);
        vector<int> res(n - k + 1);
        dq.push_back(nums[0]);
        for(int i = 1; i < k; i++){
            while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }
        res[0] = dq.front();
        
        for(int i = k; i < n; i++){
            while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            if(dq.front() == nums[i - k])dq.pop_front();
            res[i - k + 1] = dq.front();
        }

        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> a{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    for(auto n: s.maxSlidingWindow(a, k)) cout << n << ' ';
}
