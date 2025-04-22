/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi=0;
    int diameter(TreeNode* root){
        if(root==NULL)return 0;

        int left=diameter(root->left);
        int right=diameter(root->right);
        maxi=max(maxi,left+right+1);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);

        return maxi-1;
    }
};