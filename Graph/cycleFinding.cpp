#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2501;
const int maxM = 5001;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge
{
  int a, b;
  ll c;
} edges[maxM];

int n, m, ptr, p[maxN];
ll dp[maxN];

int main()
{
  cin >> n >> m;
  for (int i = 0, a, b; i < m; i++)
  {
    ll c;
    cin >> a >> b >> c;
    edges[i] = {a, b, c};
  }

  ptr = -1;
  fill(dp + 2, dp + n + 1, INF);
  for (int iter = 0; iter < n && ptr; iter++)
  {
    ptr = 0;
    for (int i = 0; i < m; i++)
    {
      int u = edges[i].a;
      int v = edges[i].b;
      ll w = edges[i].c;

      if (dp[v] > dp[u] + w)
      {
        dp[v] = dp[u] + w;
        p[v] = u;
        ptr = v;
      }
    }
  }

  if (!ptr)
  {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++)
    ptr = p[ptr];

  vector<int> cycle;
  for (int v = ptr;; v = p[v])
  {
    cycle.push_back(v);
    if (v == ptr && (int)cycle.size() > 1)
      break;
  }
  reverse(cycle.begin(), cycle.end());

  cout << "YES" << endl;
  int K = (int)cycle.size();
  for (int i = 0; i < K; i++)
  {
    cout << cycle[i];
    if (i < K - 1)
      cout << " ";
  }
  cout << endl;
}
