#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    int x = n + 1, y = sum + 1;
    int dp[x][y];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;

            else if (i == 0)
                dp[i][j] = 0;

            else if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j < y; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);

            else if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n][sum] == 1)
        return true;

    return false;
}

bool equalPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if ((sum / 2) % 2 == 0)
    {
        return (subsetSum(arr, n, sum / 2));
    }

    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool flag = equalPartition(arr, n);
    cout << flag;

    return 0;
}
