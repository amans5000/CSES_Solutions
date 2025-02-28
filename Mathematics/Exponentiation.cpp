#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll calculate(ll a, ll b)
{
  if (b == 1)
  {
    return a;
  }
  ll ans = calculate(a, b / 2);
  if (b % 2 == 0)
  {
    return (ans * ans) % mod;
  }
  else
  {
    return ((((ans * ans) % mod) * a) % mod);
  }
}

void solve(ll a, ll b)
{
  if (b == 0)
  {
    cout << 1 << endl;
    return;
  }
  if (a == 0 || a == 1)
  {
    cout << a << endl;
    return;
  }

  ll ans = calculate(a, b);

  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    ll a, b;
    cin >> a >> b;
    solve(a, b);
  }
  return 0;
}
