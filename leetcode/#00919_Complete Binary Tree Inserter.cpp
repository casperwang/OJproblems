//Complete Binary Tree Inserter: implementation
#include <cmath>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    int c = 0;
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root = root;
        dfs(root);
    }

    void dfs(TreeNode *p) {
        c++;
        if (p->left != NULL) dfs(p->left);
        if (p->right != NULL) dfs(p->right);
    }

    int insert(int v) {
        c++;
        int j = 1;
        for (; j <= c; j*=2);
        TreeNode* p = root;
        j /= 4;
        while (j > 1) {
            if ((c&j) == 0) p = p->left;
            else p = p->right;
            j /= 2;
        }
        if (c%2 == 0) p->left = new TreeNode(v);
        else p->right = new TreeNode(v);
        return p->val;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
