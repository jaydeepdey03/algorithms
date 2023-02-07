class Solution {
public:
    bool matchWord(map<char, int> freq, string s){
        if(s.length() == 0){
            return false;
        }
        map<char, int> temp;
        for(int i = 0; i<s.length(); i++){
            if(freq.find(s[i]) != freq.end()){
                temp[s[i]]++;
                if(temp[s[i]] >= freq[s[i]]){
                    freq[s[i]]-= temp[s[i]];
                }
            }
        }
        
        for(auto i: freq){
            if(i.second>0){
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        map<char, int> freq;
        for(auto b: B){
            map<char, int> temp;
            for(int i = 0; i<b.length(); i++){
                temp[b[i]]++;
                freq[b[i]] = max(freq[b[i]], temp[b[i]]);
            }
        }
        
        for(auto a: A){
            bool found = matchWord(freq, a);
            if(found){
               ans.push_back(a); 
            }
        }
        
        return ans;
    }
};