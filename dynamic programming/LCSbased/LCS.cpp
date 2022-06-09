// longest common subsqueuence Bottom-up

class Solution {
public:
    int LCS(string x, string y, int n, int m){
        
        int dp[1001][1001];
        
        memset(dp, -1, sizeof(dp));
        
        if(dp[n][m] != -1)return dp[n][m];
        
        if(n == 0 || m == 0) return 0;
        
        if(x[n-1] == y[m-1]){
            return dp[n][m] =  1 + LCS(x, y, n-1, m-1);
        }
        
        else {
            return dp[n][m] = max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));
        }
    }
    
    int longestCommonSubsequence(string x, string y) {
        int n = x.length();
        int m = y.length();
        
        return LCS(x, y, n, m);
    }
};

// LCS top-down

class Solution {
public:    
    int longestCommonSubsequence(string x, string y) {
         // initialization
        
        int n = x.length();
        int m = y.length();
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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};