#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    vector<int> s;
    vector<int> s_min;
    
public:
    MinStack() {
    }
    
    void push(int val) {
        s.emplace_back(val);
        if(s.size() == 1) s_min.emplace_back(val);
        else s_min.emplace_back(min<int>(s_min.back(), val));
    }
    
    void pop() {
        s.pop_back();
        s_min.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return s_min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

