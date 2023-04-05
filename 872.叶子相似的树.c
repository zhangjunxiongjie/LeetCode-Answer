/*
 * @lc app=leetcode.cn id=872 lang=c
 *
 * [872] 叶子相似的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recursionTree(struct TreeNode* root, char *assistant, char *assistantCounter)
{
    if (root == NULL) {

    }
    else {

        if ((root->left == NULL) && (root->right == NULL)) {

            assistant[(*assistantCounter)] = root->val;
            
            // printf ("%d, ", (*assistantCounter));

            (*assistantCounter) += 1;
        }
        else {

            if (root->left != NULL) {

                recursionTree(root->left, assistant, assistantCounter);
            }

            if (root->right != NULL) {

                recursionTree(root->right, assistant, assistantCounter);
            }
        }
    }

    return ;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    
    char assistantRoot1[200];
    char assistantRoot1Counter = 0;

    char assistantRoot2[200];
    char assistantRoot2Counter = 0;

    bool resultBool = false;

    recursionTree(root1, assistantRoot1, &assistantRoot1Counter);
    recursionTree(root2, assistantRoot2, &assistantRoot2Counter);
    
    if (assistantRoot1Counter == assistantRoot2Counter) {
        
        int i = 0;

        for (; i < assistantRoot1Counter; i++) {

            if (assistantRoot1[i] != assistantRoot2[i]) {

                resultBool = false;
                break;
            }
        }

        if (i == assistantRoot1Counter) {
            
            resultBool = true;
        }
    }
    else {
        resultBool = false;
    }
    
    return resultBool;
}

// @lc code=end

