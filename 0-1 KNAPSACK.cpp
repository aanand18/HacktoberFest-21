#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int w;
    cin >> w;

    vector<int> wt(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int dp[n + 1][w + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][w] << endl;

    /* for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}