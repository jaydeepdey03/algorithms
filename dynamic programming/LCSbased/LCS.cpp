// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string x, string y, int n, int m)
    {
       if(n==0 || m == 0)return 0;
       if(x[n-1] == y[m-1]){
           return 1+longestCommonSubstr(x, y, n-1, m-1);
       }
       else{
           return max(longestCommonSubstr(x, y, n-1, m), longestCommonSubstr(x, y, n, m-1));
       }
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends