/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
    // 时间复杂度和空间复杂度较高有待优化。
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string resultStr;
        
        queue<TreeNode*> rank;
        rank.push(root);

        int rankNumber = 1;
        while (!rank.empty())
        {
            int tempNumber = 0;
            while (rankNumber)
            {
                TreeNode* treePointer = rank.front();
                if (treePointer != nullptr)
                {
                    rank.push(treePointer->left);
                    rank.push(treePointer->right);
                    tempNumber += 2;
                    resultStr += (to_string(treePointer->val) + "|");
                }
                else
                {
                    resultStr += "n|";
                }
                
                rank.pop();
                rankNumber--;
            }
            rankNumber = tempNumber;
        }
        
        return resultStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<TreeNode*> assist;
        int left = 0;
        int right = 0;
        while (right < data.size()) 
        {
            while (data.at(right) != '|')
            {
                right++;
            }
            
            string tempStr = data.substr(left, right - left);
            if (tempStr == "n")
            {
                assist.push_back(nullptr);
            }
            else
            {
                int temp = atoi(tempStr.c_str());
                TreeNode* node = new TreeNode;
                node->val = temp;
                assist.push_back(node);
            }
            
            right++;
            left = right;
        }
        
        // 即使 tree 为空 assist 也至少有一个 nullptr 的指针。
        TreeNode* resultTree = assist.at(0); 
        int pointer = 1;
        for (int iter = 0; iter < assist.size(); iter++)
        {
            if (assist.at(iter) != nullptr)
            {
                assist.at(iter)->left = assist.at(pointer++);
                assist.at(iter)->right = assist.at(pointer++);
            }
            if (pointer > assist.size())
            {
                break;
            }
        }
        return resultTree;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

