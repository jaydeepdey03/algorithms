// #include <iostream>
// #include <vector>
// #include <map>
// #include <climits>

// using namespace std;

// bool cmp(pair<string, int> &a,
//          pair<string, int> &b)
// {
//     return a.second < b.second;
// }

// int main()
// {
//     long long x;
//     vector<int> tube;
//     vector<int> res;

//     while (1)
//     {
//         cin >> x;
//         if (x == -1)
//             break;

//         if (x == 1)
//         {
//             int a;
//             cin >> a;
//             tube.push_back(a);
//         }
//         else
//         {
//             int max = INT_MIN;
//             int indexmin = INT_MIN;
//             map<int, int> map1;
//             int eler;
//             for (int i = 0; i < tube.size(); i++)
//             {
//                 map1[tube[i]]++;
//             }
//             for (int i = 0; i < tube.size(); i++)
//             {
//                 int a = tube[i];
//                 auto itr = map1.find(a);
//                 if (itr->second <= indexmin)
//                 {

//                     indexmin = i;
//                 }
//             }
//             res.push_back(tube[indexmin]);
//             tube.erase(tube.begin() + indexmin);
//             map1[tube[indexmin]]--;
//         }
//     }
//     for (int i = 0; i < res.size(); i++)
//         cout << res[i] << " ";

//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &arr){
    for(int i = 0; i<arr.size(); i++){
        
    }
}

int main()
{
    
    return 0;
}