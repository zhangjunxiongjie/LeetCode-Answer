/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    
    struct ListNode* tail = head;
    struct ListNode* middle;
    int number = 1;

    while (tail->next)   // 得到尾节点，清点节点数
    {
        tail = tail->next;
        number++;
    }
    tail->next = head;         // 构成循环链表
    tail = head;             // 从头结点开始移动
    
    k = number - k % number;   // 计算需要移动的次数
    
    while (k)       // 进行移动
    {
        middle = tail;
        tail = tail->next;
        k--;    
    }
    
    middle->next = NULL;
    head = tail;

    return head;
}



