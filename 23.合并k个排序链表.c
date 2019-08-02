/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个排序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 第二版， 完全优化的一个思路



/* // 第一版,时间复杂度较高
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;

    struct ListNode* table[listsSize]; // 用于辅助记录指针位置
    
    struct ListNode* result_head = NULL;  // 设置初始值 
    struct ListNode* result = result_head;

    // 其实可以直接使用传入的指针数组但是作为编程规范还是不要轻易动传入参数
    for (int i = 0; i < listsSize; i++)
    {
        table[i] = lists[i];
    }

    bool flag = true;
    while (flag)
    {
        flag =false;
        int min = INT_MAX;  // 找最小值当然初值要设置为最大值了哈哈；
        int i_memory = 0;

        // 用于记录下空的链表和不空的链表然后进行移动以减少内遍历次数
        int null_i = -1;
        int tail_i = -1;

        // 这里有优化的可能就是对于移动节点到NULL的指针数组可以不再遍历
        for (int i = 0; i < listsSize; i++)
        {
            // 保证记录下来的空链表在tail_i前面
            if (table[i] == NULL)
            {
                if(tail_i == -1 && null_i != -1)
                    null_i = i;  // 记录下为空的链表
            }
            else
            {
                tail_i = i;   // 记录下不为空的链表

                // 此处考虑到了一种特殊情况就是节点值为int最大值的情况
                if (min >= table[i]->val) 
                {
                    min = table[i]->val;
                    i_memory = i;
                }

                flag = true;
            }
            
        }
        if (result_head && flag)
        {
            result_head->next = table[i_memory];
            
            // 移动指针；
            result_head = result_head->next;
            table[i_memory] = table[i_memory]->next;
        }
        else if(flag)
        {
            result_head = table[i_memory];
            result = result_head;

            table[i_memory] = table[i_memory]->next;
        }

        if (null_i != -1 && tail_i != -1)
        {
            table[null_i] = table[tail_i];
            listsSize--;
        }
        
    }
    

    return result;
}
*/

