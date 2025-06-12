#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> tunnel(n + 1); // to ,score
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    tunnel[a].push_back({b, c});
  }
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
