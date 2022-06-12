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