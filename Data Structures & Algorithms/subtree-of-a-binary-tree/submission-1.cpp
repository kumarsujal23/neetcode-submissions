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
    bool same(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot)
        return true;
        else if(!root && subRoot!=NULL)
        return false;
        else if(!subRoot && root!=NULL)
        return false;
        bool con1=same(root->left,subRoot->left);
        bool con2=same(root->right,subRoot->right);
        bool con3= root->val==subRoot->val;
        return (con1 && con2 && con3);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool con1=same(root,subRoot);
        bool con2= root?isSubtree(root->left,subRoot):false;
        bool con3= root?isSubtree(root->right,subRoot):false;
        return (con1 || con2 || con3);

    }
};
