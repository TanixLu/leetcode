#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l = head, *p;
        for(int i = 0; i < left - 1; i++)l = l->next;
        p = l;
        vector<int> temp;
        for(int i = 0; i < (right - left + 1) / 2; i++, p = p->next)temp.emplace_back(p->val);
        if((right - left) % 2 == 0)p = p->next;
        for(int i = 0; i < (right - left + 1) / 2; i++, p = p->next)swap(p->val, temp[temp.size() - 1 - i]);
        for(int i = 0; i < (right - left + 1) / 2; i++, l = l->next)swap(l->val, temp[i]);
        return head;
    }
};
// @lc code=end

int main(){
    Solution s;
    int left = 2, right = 5; vector<int> nums{1,2,3,4,5};

    ListNode *head = new ListNode(nums.front());
    ListNode *p = head;
    for(int i = 1; i < nums.size(); i++, p = p->next)p->next = new ListNode(nums[i]);
    s.reverseBetween(head, left, right);
    p = head;
    while(p != nullptr){
        cout << p->val << ' ';
        p = p->next;
    }
}
