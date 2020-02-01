/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr){
            return false;
        }
        
        // 使用快慢指针判断链表是否有环。
        ListNode *p = head, *p2 = head;
        while (p2->next != nullptr && p2->next->next != nullptr) {
            p = p->next;
            p2 = p2->next->next;
            if (p == p2) { // 有环才会出现慢指针追上快指针的情况
                return true;
            }
        }

        return false;
    }
    /*
    // 有待优化。
    bool hasCycle(ListNode *head) {
        ListNode* cache = head;
        while (cache && cache->next)
        {
            cache = cache->next;

            ListNode* move = head;
            while (move != cache && move != cache->next)
            {
                move = move->next;
            }
            
            if (move == cache)
            {
                if (move == head) //只有头结点且自己指向自己. 
                {
                    return true;
                }
                else if (move == cache->next) // 下一个节点指向 move 指针。
                {
                    return true;
                }
            }
            if(move == cache->next)
            {
                return true;
            }
            
        }
        return false;
    }
    */
};
// @lc code=end

