#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

ll coinComb(int n, vector<ll> &dp, vector<int> &coins)
{
  if (n == 0)
  {
    return 1;
  }

  if (n < 0)
  {
    return 0;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  ll val = 0;
  for (int i = 0; i < coins.size(); i++)
  {
    if (coins[i] <= n)
      val += coinComb(n - coins[i], dp, coins) % mod;
  }

  dp[n] = val % mod;
  return dp[n];
}

int main()
{
  int n, x;
  cin >> n >> x;

  vector<ll> dp(x + 1, -1);

  vector<int> coins(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  ll result = coinComb(x, dp, coins);
  cout << result << endl;

  return 0;
}