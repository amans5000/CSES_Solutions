#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll minCoins(int n, vector<ll> &dp, vector<int> &coins)
{
  if (n < 0)
  {
    return 0;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  ll minVal = INT_MAX;
  for (auto i : coins)
  {
    if (i <= n)
      minVal = min(minVal, (dp[i] + minCoins(n - i, dp, coins)));
  }
  dp[n] = minVal;
  return dp[n];
}

int main()
{
  int n, x;
  cin >> n >> x;

  vector<ll> dp(x + 1, -1);
  dp[0] = 0;

  vector<int> coins(n);

  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
    if (coins[i] <= x)
      dp[coins[i]] = 1;
  }

  ll result = minCoins(x, dp, coins);
  if (result == INT_MAX)
    cout << -1;
  else
    cout << result;

  return 0;
}
