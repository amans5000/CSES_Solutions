#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll diceComb(int n, vector<ll> &dp)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;

  if (dp[n] != -1)
  {
    return dp[n];
  }

  ll sum = 0;
  for (int i = 1; i <= 6; i++)
  {
    sum = (sum + diceComb(n - i, dp)) % mod;
  }

  dp[n] = sum;
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  vector<ll> dp(n + 1, -1);
  dp[0] = 1;
  dp[1] = 1;

  ll result = diceComb(n, dp);
  cout << result;

  return 0;
}