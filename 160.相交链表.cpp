/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // 内存使用还有待优化。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> listA;
        vector<ListNode*> listB;
        while (headA)
        {
            listA.push_back(headA);
            headA = headA->next;
        }
        while (headB)
        {
            listB.push_back(headB);
            headB = headB->next;
        }
        
        ListNode* buffer = nullptr;
        while (!listA.empty() && !listB.empty() && listA.back() == listB.back())
        {
            buffer = listA.back();
            listA.pop_back();
            listB.pop_back();
        }

        return buffer;
    }
};
// @lc code=end

