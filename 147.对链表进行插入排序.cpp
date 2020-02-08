/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    // 直接对节点指针进行修改。
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* move = head;        
        ListNode* tail = head; // 已排序链表尾节点。
        while (move)
        {
            ListNode* move1 = head;
            if (move1 == move) // 头结点
            {
                move = move->next;
                continue;
            }
            else if (move1->val > move->val) // 插入到头结点 
            {
                ListNode* buffer = head;
                head = move;
                move = move->next;
                head->next = buffer;
                tail->next = move;
            }
            else // 插入到其他位置。 
            {
                while(move1->next != move)
                {
                    if (move->val < move1->next->val)
                    {
                        break;
                    }    
                    move1 = move1->next;
                }    

                if (move1->next != move)
                {
                    ListNode* buffer = move1->next;
                    move1->next = move;
                    move = move->next;
                    move1->next->next = buffer;
                    tail->next = move;
                }
                else
                {
                    tail = move;
                    move = move->next;
                }
                
            }

            /*
            ListNode* i = head;
            while (i)
            {
                cout << i->val << ":"; 
                i = i->next;
            }
            cout << endl;
            */
        }
        
        return head;
    }
};
// @lc code=end

