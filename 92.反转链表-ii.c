/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 我尽量使尽可能多的特殊情况一般化，但是head为NULL的情况始终无法很好地被一般处理所容纳
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (!head)
        return head;

    struct ListNode employeer;
    struct ListNode* employee = &employeer;
    employeer.next = head;    // 设置这个节点的目的在于省去头结点特殊处理的步骤

    // 用于计数
    int move = 0;
    
    // 始终保持其保存原链表上一节点的特点
    struct ListNode* up_node = employee;

    struct ListNode* head_node;  // 于反转段而言。
    struct ListNode* tail_node;

    // 用于辅助
    struct ListNode* assistant;

    // 用于移动
    struct ListNode* buffer = employee;
    
    while (true)
    {
    
        if (move < m)  //反转的分段处理
        {
            up_node = buffer;  // 保存上一节点指针

            buffer = buffer->next;
        }
        else if(move == m)
        {
            head_node = up_node;  // 交换段的前一指针
            
            tail_node = buffer;   // 交换段尾指针

            up_node = buffer;  // 始终保证保存上一节点指针 
            buffer = buffer->next; // 
        }
        else if(move > m && move <= n)
        {
            assistant = buffer->next;

            buffer->next = up_node;

            up_node = buffer;
            buffer = assistant;

        }
        else if(move == n + 1)
        {

            head_node->next = up_node;
            tail_node->next = buffer;

            break;
            
        }

        move++;

    }
    
    return employee->next;
}



