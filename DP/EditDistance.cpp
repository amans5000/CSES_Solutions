#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll EditDistance(ll i, ll j, const string &s1, const string &s2, vector<vector<ll>> &dp)
{
  if (i < 0)
    return j + 1;
  if (j < 0)
    return i + 1;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (s1[i] == s2[j])
  {
    dp[i][j] = EditDistance(i - 1, j - 1, s1, s2, dp);
  }
  else
  {
    dp[i][j] = 1 + min({EditDistance(i - 1, j - 1, s1, s2, dp),
                        EditDistance(i, j - 1, s1, s2, dp),
                        EditDistance(i - 1, j, s1, s2, dp)});
  }

  return dp[i][j];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  ll n = s1.size();
  ll m = s2.size();
  vector<vector<ll>> dp(n, vector<ll>(m, -1));
  ll ans = EditDistance(n - 1, m - 1, s1, s2, dp);
  cout << ans << endl;

  return 0;
}
