#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, target, ans = 0, sum = 0, temp;
  cin >> n >> target;

  vector<int> v(n);
  for (auto &x : v)
  {
    cin >> x;
  }

  map<ll, ll> m;
  m[0] = 1;

  for (int i = 0; i < n; i++)
  {
    sum += v[i];
    ans += m[sum - target];
    m[sum]++;
  }

  cout << ans << endl;
  return 0;
  return 0;
}