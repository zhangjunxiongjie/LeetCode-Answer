/*
 * @lc app=leetcode.cn id=1290 lang=c
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){

    int result = 0;

    while (head != NULL)
    {
        
        if (head->val) {

            result <<= 1;
            result |= 1;
        }
        else {

            result <<= 1;
        }

        head = head->next;
    }

    return result;
}


// @lc code=end

