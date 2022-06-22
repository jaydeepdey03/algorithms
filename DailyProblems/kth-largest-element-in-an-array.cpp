/*
Runtime: 17 ms, faster than 29.72% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.1 MB, less than 61.91% of C++ online submissions for Kth Largest Element in an Array.
*/

// inefficient
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};


// using priority queue;

/*
Runtime: 15 ms, faster than 39.86% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.5 MB, less than 9.65% of C++ online submissions for Kth Largest Element in an Array.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto i: nums){
            q.push(i);
        }
        
        while(k!=1){
            q.pop();
            k--;
        }
        
        return q.top();
    }
};