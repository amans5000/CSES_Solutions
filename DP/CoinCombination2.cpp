#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{

  ll n, x;
  cin >> n >> x;
  vector<ll> coins(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());
  vector<ll> dp(x + 1, 0);

  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = coins[i]; j <= x; j++)
    {
      dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
    }
  }
  cout << dp[x];
}
