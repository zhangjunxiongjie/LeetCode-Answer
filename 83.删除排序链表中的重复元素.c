/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 第二版，一遍遍历,且省去中间指针变量。
struct ListNode* deleteDuplicates(struct ListNode* head){

    struct ListNode* first = head;

    while (first && first->next)
    {
        if(first->val != first->next->val)
        {
            first = first->next;
        }
        else
        {   
            first->next = first->next->next; 
        }
        
    }
    
    return head;
}



/* 
// 第一版，每次找出下一个不同节点。
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* move = head;
    struct ListNode* first = NULL;

    while (move)
    {
        int middle = move->val;
        while (move->next && middle == move->next->val)
        {
            move = move->next;
        }
        
        if (!first)
        {
            first = move;
            head = first;
        }
        else
        {
            first->next = move;
            first = first->next; 
        }
        
        move = move->next;
    }
    
    return head;
}
*/


