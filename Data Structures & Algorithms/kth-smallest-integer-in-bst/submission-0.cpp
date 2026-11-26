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
    int i=0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
        return -1;
        int a=kthSmallest(root->left,k);
        if(a!=-1)
        return a;
        i++;
        if(k==i)
        return root->val;
        return kthSmallest(root->right,k);
    }
};
