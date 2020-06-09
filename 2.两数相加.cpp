/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = new(struct ListNode);
        ListNode* resultMove = result;
        
        int carry = 0; // 进位
        bool flag = true;
        
        ListNode* l1Move = l1;
        ListNode* l2Move = l2;
        int l1Value = l1Move->val;
        int l2Value = l2Move->val;
        
        while (flag)
        {
            int middle = l1Value + l2Value + carry;
            if (middle >= 10)
            {
                carry = 1;
                middle -= carry * 10;
            }
            else
            {
                carry = 0;
            }
            
            resultMove->val = middle;

            if (l1Move->next != nullptr || l2Move->next != nullptr || carry != 0)
            {
                if (l1Move->next != nullptr)
                {
                    l1Move = l1Move->next;
                    l1Value = l1Move->val;
                }
                else
                {
                    l1Value = 0;
                }
                
                if (l2Move->next != nullptr)
                {
                    l2Move = l2Move->next;
                    l2Value = l2Move->val;
                }
                else
                {
                    l2Value = 0;
                }

                resultMove->next = new(struct ListNode);
                resultMove = resultMove->next;

                flag = true;
            }
            else
            {
                flag = false;
            }
            
        }
        
        resultMove->next = nullptr;
        
        return result;
    }
};
// @lc code=end

