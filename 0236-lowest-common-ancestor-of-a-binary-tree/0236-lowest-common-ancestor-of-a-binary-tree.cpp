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
    TreeNode* Lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (p == root || root == q) {
            return root;
        }
        TreeNode* l1 = Lca(root->left, p, q);
        TreeNode* l2 = Lca(root->right, p, q);

        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL && l2 != NULL) {
            return l2;
        }
        if (l2 == NULL && l1 != NULL) {
            return l1;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Lca(root, p, q);
    }
};

//