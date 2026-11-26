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
    int solve(TreeNode* root)
    {
        if(!root->right)
        return root->val;
        else 
        return solve(root->right);
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return root;
        if(root->val==key)
        {
            //leaf
            if(!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            else if(!root->right)
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left)
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else 
            {
                int maxelm= solve(root->left);
                root->val=maxelm;
                root->left=deleteNode(root->left,maxelm);
                return root;
            }
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};