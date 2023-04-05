/*
 * @lc app=leetcode.cn id=876 lang=c
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    
    struct ListNode* assistantVector[100];
    int assistantVectorIndex = 0;

    while (head != NULL) {

        assistantVector[assistantVectorIndex++] = head;
        head = head->next;
    }

    return assistantVector[assistantVectorIndex / 2];
}

// @lc code=end

