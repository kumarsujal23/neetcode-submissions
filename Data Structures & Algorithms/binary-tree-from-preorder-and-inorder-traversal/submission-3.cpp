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
    unordered_map<int ,int> mp;
    int ind=0;
    TreeNode* build(int l,int r,vector<int>& preorder)
    {
        if(r<l)
        return nullptr;
        TreeNode* root=new TreeNode(preorder[ind]);
        ind++;
        int mid=mp[root->val];
        root->left=build(l,mid-1,preorder);
        root->right=build(mid+1,r,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(0,preorder.size()-1,preorder);
    }
};
