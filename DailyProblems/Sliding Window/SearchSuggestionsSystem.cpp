// in-efficient solution: Brute Force

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
    
        sort(products.begin(), products.end());
        
        
        int ptr = 0;
        string word;
        
        
        while(ptr < searchWord.length()){        
            int count = 0;
            vector<string> candidate;
            word.push_back(searchWord[ptr]);
            
            for(int i = 0; i<products.size(); i++){
                if(count == 3)break;
                string prod = products[i];
                string pref = prod.substr(0, ptr+1);
                
                if(pref == word){
                    candidate.push_back(prod);
                    count++;
                }
            }
            ptr++;
            ans.push_back(candidate);
        }
        return ans;
    }
};

// efficient solution: Trie Data Structure