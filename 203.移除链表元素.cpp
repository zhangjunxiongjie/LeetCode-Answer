/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while (head && head->val == val)
        {
            head = head->next;
        }
        
        ListNode* lastpointer = head;
        ListNode* pointer = head;
        
        while (pointer)
        {
            if (pointer->val == val)
            {
                lastpointer->next = pointer->next;
                pointer = lastpointer;
            }
            
            lastpointer = pointer;
            pointer = pointer->next;
        }
        return head;
    }
};
// @lc code=end

