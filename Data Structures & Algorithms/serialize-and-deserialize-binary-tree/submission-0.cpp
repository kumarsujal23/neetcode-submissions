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

class Codec {
public:
    void ser(TreeNode* root,vector<string> &ans)
    {
        if(!root)
        {
            ans.push_back("N");
            return;
        }
        ans.push_back(to_string(root->val));
        ser(root->left,ans);
        ser(root->right,ans);
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        ser(root,ans);
        return join(ans,",");
    }
    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deser(vector<string> &ans,int &i)
    {
        if(ans[i]=="N")
        {
            i++;
            return nullptr;
        }
        TreeNode* root=new TreeNode(stoi(ans[i]));
        i++;
        root->left=deser(ans,i);
        root->right=deser(ans,i);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> ans=split(data,',');
        int i=0;
        return deser(ans,i);
    }
     vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
};
