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
    int res=INT_MIN;
    int solve(TreeNode* root)
    {
        if(!root)
        return 0;
        int lmax=solve(root->left);
        int rmax=solve(root->right);
        res=max(res,lmax+rmax+root->val);
        return max(0,root->val+max(lmax,rmax));
    }
    int maxPathSum(TreeNode* root) {
    solve(root);
    return res;
    }
};
