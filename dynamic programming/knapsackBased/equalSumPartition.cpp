#include <iostream>
#include <vector>

using namespace std;


// top-down approach

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

bool canPartition(vector<int> &nums)
{

    int sum = 0;
    // calculating the sum of the array
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    // if the number of element is odd, there is no possible ways to partition in two different vectors such that they both have equal sum
    if (sum % 2 != 0)
        return false;

    // check if sum/2 is possible in array, if sum/2 is possible it means there can one who partitioned array which have sum/2, so automatically the other partition will have sum/2 and hence the ans is returned true. Else false 
    return subsetSum(nums, sum / 2);
}

int main()
{
    vector<int> v = {2, 3, 4, 5};
    if(canPartition(v))cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}