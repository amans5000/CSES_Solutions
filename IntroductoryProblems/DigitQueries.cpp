#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  ll k;
  cin >> k;

  ll len = 1;
  ll count = 9;
  ll start = 1;

  while (k > len * count)
  {
    k -= len * count;
    len++;
    count *= 10;
    start *= 10;
  }

  start += (k - 1) / len;
  string num = to_string(start);
  cout << num[(k - 1) % len] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
