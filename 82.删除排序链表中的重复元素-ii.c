/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* move = head;
    struct ListNode* first = NULL; 
    
    head = NULL;

    while (move)
    {
        
        // 找到下一个无重复节点
        int middle = move->val;
        while ( move->next && middle == move->next->val)
        {
            move = move->next;

            // 如果一次去重结束，移动至下一个节点。
            if (move->next && middle != move->next->val)
            {
                middle = move->next->val;
                move = move->next;
            }
            else if(!move->next) //查找到最后一个节点要特殊处理。
            {
                move = NULL;
                break;
            }
            
        }

        
        // 只有当first和head都为null时才进行初始化
        if ( !first && !head)
        {
            first = move;
            head = first;
        }
        else
        {
            first->next = move;
            first = first->next;
        }

        if (move)
        {
            move = move->next;
        }
        else
        {
            break;
        }
        
    }

    return head;
}



