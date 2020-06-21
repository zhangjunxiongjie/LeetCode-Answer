/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

    int recursion(TreeNode* root, int& maxPathSum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int leftMaxPathSum = recursion(root->left, maxPathSum);
            int rightMaxPathSum = recursion(root->right, maxPathSum);
            
            int presentMaxPathSum = max((leftMaxPathSum + root->val), (rightMaxPathSum + root->val));
            presentMaxPathSum = max(presentMaxPathSum, root->val); // 可能的情况。

            maxPathSum = max(maxPathSum, (leftMaxPathSum + rightMaxPathSum + root->val));
            maxPathSum = max(maxPathSum, presentMaxPathSum); // 单边最大。
            maxPathSum = max(maxPathSum, root->val); // 解决负数问题。
            
            return presentMaxPathSum;
        }
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        
        recursion(root, maxPathSum);

        return maxPathSum;
    }

    /*
    // 对子树多次求解应该从下往上减少计算量。
    // 递归求解时间复杂度和空间复杂度较差。
    int recursion(TreeNode* root, bool sign){
        int buffer[5];
        buffer[0] = root->val;
        if (root->left != nullptr)
        {
            buffer[1] = recursion(root->left, false);
            buffer[3] = buffer[1] + buffer[0];
        }
        else
        {
            buffer[1] = INT_MIN;
            buffer[3] = buffer[0];
        }
        if (root->right != nullptr)
        {
            buffer[2] = recursion(root->right, false);
            buffer[4] = buffer[2] + buffer[0];
        }
        else
        {
            buffer[2] = INT_MIN;
            buffer[4] = buffer[0];
        }
        
        int max = buffer[0];
        for (int i = 3; i < 5; i++)
        {
            if (buffer[i] > max)
            {
                max = buffer[i];
            }
        }

        if(sign && buffer[1] >= 0 && buffer[2] >= 0 &&buffer[0] + buffer[1] + buffer[2] > max)
        {
            max = buffer[0] + buffer[1] + buffer[2];
        }
        
        return max;    
    }

    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        if (root == nullptr)
        {
            return result;
        }
        
        queue<TreeNode*> heap;
        heap.push(root);
        while (!heap.empty())
        {
            TreeNode* p = heap.front();
            heap.pop();

            if(p != nullptr){
                if (p->left != nullptr)
                {
                    heap.push(p->left);
                }
                if(p->right != nullptr)
                {
                    heap.push(p->right);
                }
            }

            int buffer = recursion(p, true);
            if (buffer > result)
            {
                result = buffer;
            }
            
        }
        return result;
    }
    */
    
};
// @lc code=end

