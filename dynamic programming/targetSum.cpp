class Solution {
public:
    
    int subsetSum(vector<int> &arr, int sum){
        // initialization
        int n = arr.size();
        int dp[n + 1][sum + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
            dp[i][0] = 1;
 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
            // if the value is greater than the sum
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]; 
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    
    int countSumWithGivenSum(vector<int> &arr, int diff){
        int sum = 0;
        for(auto i:arr)sum+=i;
        return subsetSum(arr, (diff+sum)/2);

    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i:nums)sum+=i;
        if(sum<abs(target) || (sum+target)%2 != 0)
            return 0;
        return countSumWithGivenSum(nums, target);
    }
};