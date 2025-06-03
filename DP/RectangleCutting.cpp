#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      if (i == j)
        dp[i][j] = 0;
      else
      {
        dp[i][j] = INT_MAX;

        for (int k = 1; k < i; ++k)
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);

        for (int k = 1; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}
