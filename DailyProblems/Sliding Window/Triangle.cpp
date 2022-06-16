class Solution {
public:   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector < vector <int> > dp;
         int ans = INT_MAX;
        for (int  i = 0; i < n; i++) {
            vector <int> temp(triangle[i].size(), 0);
            dp.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (j == 0 && i == 0) {
                    dp[i][j] = triangle[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j]; 
                } else if (j == dp[i].size() - 1) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + triangle[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                }
                if (i == n - 1) ans = min(dp[n - 1][j], ans);
            }
            
        }
       
        return ans;
    }
};

// 