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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL)
            {
                res.push_back(ans);
                ans={};
                if(!q.empty())
                q.push(NULL);
            }
            else 
            {
            ans.push_back(f->val);
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
            }
            
        }
        return res;
    }
};
