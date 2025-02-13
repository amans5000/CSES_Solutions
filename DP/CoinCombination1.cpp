#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll coinComb(int n, vector<ll> &dp, vector<int> &coins)
{
  if (n < 0)
  {
    return 0;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  ll val = 0;

  dp[n] = val;
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
  }

  ll result = coinComb(x, dp, coins);
  cout << result;

  return 0;
}
