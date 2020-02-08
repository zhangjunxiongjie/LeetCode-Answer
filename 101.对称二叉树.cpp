/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 递归实现镜像比较，时间复杂度还行，空间复杂度较高。
    bool recursion(TreeNode* left, TreeNode* right){
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if(left == nullptr)
        {
            return false;
        }
        else if(right == nullptr)
        {
            return false;
        }
        else
        {
            if (right->val == left->val && recursion(left->right, right->left) && recursion(left->left, right->right))
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        
    }
    bool isSymmetric(TreeNode* root){
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return recursion(root->left, root->right);
        }
        
    }

    /*
    // 层次遍历的实现，时间和空间复杂度较高。
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> que; // 队列。
        
        que.push(root);
        int sum = que.size(); // 记录每一层的指针个数以便从队列取出。 
        bool sign = true;
        while (sign)
        {
            sign = false;
            vector<int> buffer;
            for (int i = 0; i < sum; i++)
            {
                if (que.front())
                {
                    if (sum == 1 || i < sum / 2)
                    {
                        buffer.push_back(que.front()->val);
                    }
                    else if (buffer.at(sum - 1 - i) != que.front()->val)
                    {
                        return false;
                    }
                    
                    que.push(que.front()->left);
                    que.push(que.front()->right);
                    
                    sign = true;
                }
                else
                {
                    if (sum == 1 || i < sum / 2)
                    {
                        buffer.push_back(INT_MAX);
                    }
                    else if (buffer.at(sum - 1 - i) != INT_MAX)
                    {
                        return false;
                    }
                    
                    que.push(nullptr);
                    que.push(nullptr);
                }
                
                que.pop();
            } 
            sum = que.size();
        }
        return true;
    }
    */
};
// @lc code=end

