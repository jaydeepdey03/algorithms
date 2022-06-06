#include <bits/stdc++.h>

using namespace std;

// initialization

bool subsetSum(vector<int> &nums, int sum)
{
    int n = nums.size();

    // initialization
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    // filling rest of the boxes from the previous solved boxes
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
            else
            {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> v = {2, 3, 4, 5};
    if(subsetSum(v))cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}