#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll x, y;
  cin >> x >> y;
  ll maxl = max(x, y);
  ll l = (maxl - 1) * (maxl - 1) + 1;
  ll r = maxl * maxl;

  if (x < y)
  {
    if (y % 2 == 0)
    {
      cout << l + (x - 1) << endl;
    }
    else
    {
      cout << r - (x - 1) << endl;
    }
  }
  else
  {

    if (x % 2 == 0)
    {
      cout << r - (y - 1) << endl;
    }
    else
    {
      cout << l + (y - 1) << endl;
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
