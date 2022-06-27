// O(n) - time, O(n + n) - space; 289ms

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, -1);
        
        int start = 0;
        int maxSum = 0;
        
        // prefix Sum
        for(int i = 0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        // look-up table
        vector<int> table(10001, -1);
        
        for(int i = 0; i<n; i++){
            start = max(start, table[nums[i]]+1);
            maxSum = max(maxSum, prefixSum[i+1]-prefixSum[start]);
            table[nums[i]] = i;
        }
        
        return maxSum;
    }
};


// 681 ms (problematic): O(n^2)
int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int,int> m;

    int maxSum = INT_MIN, windowSum = 0;

    int start = 0, end = 0;

    while(end < nums.size()){
        windowSum += nums[end];
        while(m.find(nums[end]) != m.end()){
            windowSum -= nums[start];
            m.erase(nums[start]);
            start++;
        }
        maxSum = max(maxSum, windowSum);
        m[nums[end]] = end;
        end++;       
    }
    return maxSum;
}

// O(n^2)-time, O(n)-space; 234ms
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        vector<bool>  dp(10001,false);
        int n=nums.size();
        int ans=-1,currSum=0;
        while(j<n){
            if(dp[nums[j]]){
                while(nums[i]!=nums[j]){
                    dp[nums[i]]=false;
                    currSum-=nums[i];
                    i++;
                }
                i++;
                j++;
            }
            else{
                dp[nums[j]]=true;
                currSum+=nums[j];
                ans=max(currSum,ans);
                j++;
            }
        }
        return ans;
    }
};