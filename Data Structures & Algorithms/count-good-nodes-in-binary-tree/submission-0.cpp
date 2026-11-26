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
    int count=0;
    TreeNode* solve(TreeNode* root,int prev)
    {
        if(!root)
        return root;
        if(root->val>=prev)
        {
            count++;
        }
        prev=max(prev,root->val);
        if(root->left)
        root->left=solve(root->left,prev);
        if(root->right)
        root->right=solve(root->right,prev);
        return root;
    }    
    int goodNodes(TreeNode* root) {
        if(!root)
        return 0;
        root=solve(root,root->val);
        return count;
    }
};
