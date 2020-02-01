/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        vector<ListNode*> heap;
        
        ListNode* move = head;
        while (move){
            heap.push_back(move);
            move = move->next;
        }

        int buffer = -1;
        for (int i = 0; i < heap.size() / 2; i++){
            if (buffer != -1){
                heap.at(buffer)->next = heap.at(i);
            }
            
            buffer = heap.size() - i - 1;
            heap.at(i)->next = heap.at(buffer);
        }

        // 0,1,2个节点时不用处理尾节点。 
        if (heap.size() >= 3){
            
            // 奇数个节点时
            if (heap.size() % 2 == 1){
                heap.at(heap.size() / 2 + 1)->next = heap.at(heap.size() / 2);
            }

            // 处理尾节点。
            heap.at(heap.size() / 2)->next = nullptr;
        }
    }
};
// @lc code=end

