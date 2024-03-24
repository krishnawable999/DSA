#include <iostream>
#include <vector>
using namespace std;

int solveUsingRE(int capacity, int wt[], int profit[], int index, int n)
{

    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }

    // inclusion / exclusiion

    int include = 0;
    int exclude = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRE(capacity - wt[index], wt, profit, index + 1, n);
    }
    exclude = solveUsingRE(capacity, wt, profit, index + 1, n);

    int ans = max(include, exclude);
    return ans;
}

int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }

    //
    if (dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }
    // inclusion / exclusiion

    int include = 0;
    int exclude = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }
    exclude = solveUsingMem(capacity, wt, profit, index + 1, n, dp);

    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int solveUsingTabulation(int capacity, int wt[], int profit[], int n)
{
    vector<vector<int>> dp(capacity+1, vector<int>(n + 1, -1));

    for (int row = 0; row <= capacity; row++)
    {
        dp[row][n] = 0;
    }

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int include = 0;
            int exclude = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + dp[i - wt[j]][j + 1];
            }
            exclude = dp[i][j + 1];

            dp[i][j] = max(include, exclude);
        }
    }

    return dp[capacity][0];
}

int main()
{
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;
    int n = 3;
    // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    int ans = solveUsingTabulation(capacity, wt, profit, n);
    cout << ans;
    // int ans = solveUsingRE(capacity, wt, profit, index, n);
    // cout<<ans<<endl;
}