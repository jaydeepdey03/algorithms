class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return ans;
    }
    
};