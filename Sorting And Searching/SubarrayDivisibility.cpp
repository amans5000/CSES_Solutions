#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, ans = 0, sum = 0;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v)
  {
    cin >> x;
  }

  map<ll, ll> m;
  m[0] = 1;

  for (int i = 0; i < n; i++)
  {
    sum = (sum + v[i]) % n;
    if (sum < 0)
      sum += n;

    ans += m[sum];
    m[sum]++;
  }

  cout << ans << endl;
  return 0;
}
