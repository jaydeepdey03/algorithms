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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            vector<int> level;
            while(siz--){
                TreeNode* ele = q.front();
                q.pop();
                level.push_back(ele->val);
                if(ele->left!=NULL)q.push(ele->left);
                if(ele->right!=NULL) q.push(ele->right);
            }
            
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end()); // one extra line
        return ans;
    }
};