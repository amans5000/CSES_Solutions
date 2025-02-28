#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll calculate(ll base, ll exp, ll m)
{
  ll res = 1;

  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % m;
    base = (base * base) % m;
    exp /= 2;
  }

  return res;
}

void solve(ll a, ll b, ll c)
{
  if (c == 0)
  {
    cout << a % mod << endl;
    return;
  }
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

  ll BpowerC = calculate(b, c, mod - 1);
  ll result = calculate(a, BpowerC, mod);

  cout << result << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
  }
  return 0;
}
