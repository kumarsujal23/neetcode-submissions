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
    bool res=true;
    int solve(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        bool cond=abs(l-r)<=1;
        res= res && cond;
        return max(l,r)+1;

    }
    bool isBalanced(TreeNode* root) {
        int a=solve(root);
        return res;
    }
};
