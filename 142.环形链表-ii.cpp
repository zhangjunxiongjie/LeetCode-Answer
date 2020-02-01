/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    // 使用快慢指针判断是否有环。
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr){
            return nullptr;
        }
        
        // 步骤一：使用快慢指针判断链表是否有环
        ListNode *p = head, *p2 = head;
        bool hasCycle = false; // 是否有环的标志。
        while (p2->next != nullptr && p2->next->next != nullptr) {
            p = p->next;
            p2 = p2->next->next;
            if (p == p2) { // 有环才会出现慢指针追上快指针的情况
                hasCycle = true;
                break;
            }
        }
        cout << p->val << endl;
        // 步骤二：若有环，找到入环开始的节点
        // 上一步中慢指针的终点到环起点的距离与链表起点与环起点距离相同。故此下面这样才能直接得到环起点。
        if (hasCycle) {
            ListNode *q = head;
            while (p != q) {
                cout << p->val << ":" << q->val << endl;
                p = p->next;
                q = q->next;
            }
            return q;
        } else 
            return nullptr;
    }

    /*
    // 时间复杂度较大。
    ListNode *detectCycle(ListNode *head) {
        ListNode* cache = head;
        
        while (cache && cache->next){
            
            cache = cache->next;

            ListNode* move = head;
            while (move != cache && move != cache->next){
                move = move->next;
            }
            // 只有一个节点且头结点指向自己。
            if (move == cache && move == head){
                return move;
            }
            // 当前节点的下一个节点是已经经过的节点。
            if(cache->next == move){
                return move;
            }
        }
        return nullptr;
    }
    */
};
// @lc code=end

