#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0LL; i < n; i++)
  {
    cin >> arr[i];
  }

  ll sum = accumulate(arr.begin(), arr.end(), 0LL);
  vector<bool> dp(sum + 1, -1);
  dp[0] = 0;

  for (ll i = 0LL; i < n; i++)
  {
    for (ll j = sum; j >= arr[i]; j--)
    {
      if (dp[j - arr[i]] != 0)
      {
        dp[j] = 1;
      }
    }
  }

  cout << count(dp.begin(), dp.end(), 1) << endl;
  for (ll i = 1; i <= sum; i++)
  {
    if (dp[i] == 1)
    {
      cout << i << " ";
    }
  }

  return 0;
}
