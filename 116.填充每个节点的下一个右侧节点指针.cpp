/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que; // 队列。
        if (root)
        {
            que.push(root);
        }
        else
        {
            return root;
        }
        
        int sum = que.size(); // 记录每一层的指针个数以便从队列取出。 
        while (sum != 0)
        {
            for (int i = 0; i < sum; i++)
            {
                if (que.front()->left)
                {
                    que.push(que.front()->left);
                    que.push(que.front()->right);
                }
                
                Node* node = que.front();
                que.pop();
                if (i + 1 == sum) // 最右边指针。
                {
                    node->next = nullptr;
                }
                else
                {
                    node->next = que.front();
                }
            } 
            sum = que.size();
        }
        return root;
    }
};
// @lc code=end

