#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    int x = n + 1;
    int y = sum + 1;

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
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][sum] << endl;
    /*for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }*/

    return 0;
}