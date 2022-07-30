class Solution {
public:
    
    void inorder(TreeNode* root, int level, map<int, int> &mp){
        if(root == nullptr)return;
        inorder(root->left, level+1, mp);
        mp[level] = root->val;
        inorder(root->right, level+1, mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;
        vector<int> ans;
        
        inorder(root, 0, mp);
        
        for(auto itr = mp.begin(); itr!=mp.end(); itr++){
            ans.push_back(itr->second);
        }
        
        return ans;
    }
};