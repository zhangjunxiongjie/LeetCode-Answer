/*
 * @lc app=leetcode.cn id=1496 lang=c
 *
 * [1496] 判断路径是否相交
 */

// @lc code=start


struct TREE_NODE {

    int node_value;

    struct TREE_NODE *left_tree;
    struct TREE_NODE *right_tree;

} tree_node;


bool treeInsert(struct TREE_NODE *root, int node_value)
{
    struct TREE_NODE *node = malloc(sizeof(struct TREE_NODE));

    node->node_value = node_value;
    node->left_tree = NULL;
    node->right_tree = NULL;

    while (root->node_value != node->node_value) {

        if (root->node_value > node->node_value) {

            if (root->left_tree != NULL) {
                
                root = root->left_tree;
            }
            else {

                root->left_tree = node;
                return false;
            }
        }
        else if (root->node_value < node->node_value) {

            if (root->right_tree != NULL) {

                root = root->right_tree;
            }
            else {

                root->right_tree = node;
                return false;
            }
        }
    }

    return true;
}

void treeErase(struct TREE_NODE *root)
{

    return ;
}

struct TREE_NODE *treeInit(int node_value) 
{    
    struct TREE_NODE *root = malloc(sizeof(struct TREE_NODE));

    root->left_tree = NULL;
    root->right_tree = NULL;
    root->node_value = node_value;

    return root;
}

bool isPathCrossing(char * path){
    
    struct TREE_NODE *searchTreeRoot = treeInit(0);
    
    int site = 0;

    for (char *pathPointer = path; pathPointer < (path + strlen(path)); pathPointer++) {

        switch (*pathPointer) {

            case 'N': {
                site += 1;
                break;
            }
            case 'E': {
                site += 10001;
                break;
            }
            case 'S': {
                site -= 1;
                break;
            }
            case 'W': {
                site -= 10001;
                break;
            }
            default : {
                // 异常
                break;
            }
        }

        if (treeInsert(searchTreeRoot, site)) {

            return true;
        }
    }

    // 清空二叉搜索树
    treeErase(searchTreeRoot);

    return false;
}

// @lc code=end

