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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr)
                {
                    ans+=to_string(curr->val)+",";
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else{
                    ans+="#,";
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string temp;
        getline(ss,temp,',');
        if(data.size()==0)
        {
            return nullptr;
        }
        TreeNode* root=new TreeNode(stoi(temp));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            getline(ss,temp,',');
            if(temp=="#")
            {
                curr->left=nullptr;
            }
            else
            {
                curr->left=new TreeNode(stoi(temp));
                q.push(curr->left);
            }
            getline(ss,temp,',');
            if(temp=="#")
            {
                curr->right=nullptr;
            }
            else
            {
                curr->right=new TreeNode(stoi(temp));
                q.push(curr->right);
            }
        }
        return root;
    }
};
