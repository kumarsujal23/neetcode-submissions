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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL)
            {
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                TreeNode* s=q.front();
                if(s==NULL)
                ans.push_back(f->val);
                if(f->left)
                q.push(f->left);
                if(f->right)
                q.push(f->right);
            }

        }
        return ans;
    }
};
