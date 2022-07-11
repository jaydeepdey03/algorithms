// top-down approach: 4ms, 13.7mb memory

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        
        for(int i = 0; i<n; i++){
            if(i<2) dp[i] = cost[i];
            else{
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            }
            
        }
        return min(dp[n-1], dp[n-2]);
    }
};


// bottom-up dp

// TLE 🥲 😢

class Solution {
public:
    int minCost(vector<int> &cost, int n, int i){
        
        if(i>=n)return 0; 
        
        int first = cost[i] + minCost(cost, n, i+1);
        
        int second = cost[i] + minCost(cost, n, i+2);

        return min(first, second);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), i = 0;
        int dp[n+1];
        return min(minCost(cost, n, i) , minCost(cost, n, i+1));
    }
};
