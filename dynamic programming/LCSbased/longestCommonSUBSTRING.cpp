class Solution{
    public:
    
    int longestCommonSubstr (string x, string y, int n, int m)
    {
        // initialization
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)dp[i][j] = 0;
                if (j == 0)dp[i][j] = 0;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[n][m];
    }
};