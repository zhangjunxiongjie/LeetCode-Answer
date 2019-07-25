/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 
 进行链表遍历然后将大于或等于x的值向后交换，
交换的前提是其后面存在值小于x的节点
但是这种方法会改变节点的相对位置。
另一种不会改变节点相对位置的方法是直接移动节点(连带移动)，下面是具体实现。
*/ 
struct ListNode* partition(struct ListNode* head, int x){
    
    struct ListNode assistant;
    
    assistant.next = head;
    
    struct ListNode* left = &assistant;
    
    struct ListNode* move = NULL;

    while (true)
    {
        
        while (left->next && left->next->val < x)
        {
            left = left->next;
        }

        move = left->next;
        
        while (move && move->next && move->next->val >= x)
        {
            move = move->next;
        }

        // 连带交换
        if (move && move->next)
        {
            struct ListNode* middle;
            
            middle = left->next;
            
            left->next = move->next;

            left = left->next;
            
            move->next = left->next;
            
            left->next = middle;
            
        }
        else
        {
            break;
        }

        /* 纯粹的节点交换
        if (move->next && left->next)
        {
            struct ListNode* middle;
            
            middle = left->next;
            
            left->next = move->next;
            move->next = middle;
            
            left = left->next;
            move = move->next;
            middle = left->next;

            left->next = move->next;
            move->next = middle;
            
        }
        else
        {
            break;
        }
        */

    }

    return assistant.next;
}



