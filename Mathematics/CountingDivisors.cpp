#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  int count = 0;

  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      count += 2;
      if (i * i == n)
        count--;
    }
  }

  cout << count << endl;
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
