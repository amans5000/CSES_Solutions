#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXNUM = 2e5 + 5;

void solve()
{
  int n;

  cin >> n;
  vector<int> l(MAXNUM);
  vector<int> r(MAXNUM);
  vector<ll> a(MAXNUM);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
  {
    l[i] = i - 1;
    while (a[l[i]] >= a[i])
      l[i] = l[l[i]];
  }
  for (int i = n; i >= 1; i--)
  {
    r[i] = i + 1;
    while (a[r[i]] >= a[i])
      r[i] = r[r[i]];
  }

  ll best = 0LL;
  for (int i = 1; i <= n; i++)
    best = max(best, (r[i] - l[i] - 1) * a[i]);
  cout << best << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
