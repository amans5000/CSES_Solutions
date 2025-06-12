#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  string s, x;
  cin >> s >> x;

  ll n = s.length(), m = x.length();

  if (n < m)
  {
    cout << 0 << endl;
    return;
  }
  vector<ll> LPS(m);

  // Constructing LPS (Longest Proper Prefix which is also Suffix) array for pattern x
  for (int i = 1, len = 0; i < m;)
  {
    if (x[i] == x[len])
    {
      len++;
      LPS[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = LPS[len - 1];
      }
      else
      {
        LPS[i] = 0;
        i++;
      }
    }
  }

  int i = 0, j = 0;
  int count = 0;
  while (i < n)
  {
    if (s[i] == x[j])
    {
      i++;
      j++;
    }
    if (j == m)
    {
      count++;
      j = LPS[j - 1];
    }
    else if (i < n && s[i] != x[j])
    {
      if (j != 0)
        j = LPS[j - 1];
      else
        i++;
    }
  }
  cout << count << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
