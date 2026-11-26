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
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL)
        return {0,0};
        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);
        pair<int,int> res;
        res.first=max(max(l.first,r.first),l.second+r.second+1);
        res.second=max(l.second,r.second)+1;
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> res=solve(root);
        return res.first-1;
    }
};
