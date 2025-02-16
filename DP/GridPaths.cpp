#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll gridpaths(int l, int b, vector<vector<ll>> &dp, vector<vector<char>> &grid)
{

  if (l < 0 || b < 0)
  {
    return 0;
  }

  if (dp[l][b] != -1)
  {
    return dp[l][b];
  }

  if (grid[l][b] == '*')
  {
    return 0;
  }

  dp[l][b] = (gridpaths(l - 1, b, dp, grid) + gridpaths(l, b - 1, dp, grid)) % mod;
  return dp[l][b];
}

int main()
{
  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  if (grid[0][0] != '*')
    dp[0][0] = 1;

  dp[n - 1][n - 1] = gridpaths(n - 1, n - 1, dp, grid);
  cout << dp[n - 1][n - 1];

  return 0;
}