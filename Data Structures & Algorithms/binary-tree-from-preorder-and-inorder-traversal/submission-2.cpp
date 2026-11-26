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
    unordered_map<int,int> mp;
    int indx=0;
    TreeNode* dfs(int l,int r,vector<int>& preorder)
    {
        if(r<l)
        return nullptr;
        TreeNode* root=new TreeNode(preorder[indx]);
        indx++;
        int mid=mp[root->val];
        root->left=dfs(l,mid-1,preorder);
        root->right=dfs(mid+1,r,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return dfs(0,inorder.size()-1,preorder);
    }
};
