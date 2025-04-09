/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Lcs(TreeNode*root,TreeNode*r1,TreeNode*r2){
        if(root==NULL){
            return NULL;
        }
        if(r1==root || r2==root){
            return root;
        }
        TreeNode*left=Lcs(root->left,r1,r2);
        TreeNode*right=Lcs(root->right,r1,r2);
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left==NULL && right!=NULL){
            return right;
        }
         if(left!=NULL && right==NULL){
            return left;
        }
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return NULL;

        vector<TreeNode*> ans;

        int lev = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            ans={};
            while (sz--) {
                auto it = q.front();
               // cout<<it->val<<" ";
                q.pop();
                ans.push_back(it);
                if (it->left) {
                    q.push(it->left);
                    ans = {};
                }
                if (it->right) {
                    q.push(it->right);
                    ans = {};
                }
            }
            cout<<endl;
        }
        if(ans.size()==1)return ans[0];
        TreeNode*prev=ans[0];
        TreeNode*res;
       for(int i=1;i<ans.size();i++){
        TreeNode*lc=Lcs(root,prev,ans[i]);
        res=lc;
        prev=lc;
       }

        return res;
    }
};