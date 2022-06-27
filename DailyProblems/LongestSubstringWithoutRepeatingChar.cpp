#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, mx = INT_MIN;
        unordered_map<char, int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size() < j-i+1){
                j++;
            }
            else if(mp.size() == j-i+1){
                mx = max(mx, j-i+1);
                j++;
            }
            else if(mp.size() > j-i+1){
                while(mp.size() > j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};

int main(){
    return 0;
}