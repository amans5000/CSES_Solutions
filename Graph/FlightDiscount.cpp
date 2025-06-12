#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; ++i)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

  dist[1][0] = 0;
  pq.push(make_tuple(0, 1, 0));

  while (!pq.empty())
  {
    ll d;
    int u, used;
    tie(d, u, used) = pq.top();
    pq.pop();

    if (d > dist[u][used])
      continue;

    for (size_t i = 0; i < adj[u].size(); ++i)
    {
      int v = adj[u][i].first;
      int w = adj[u][i].second;

      if (dist[v][used] > dist[u][used] + w)
      {
        dist[v][used] = dist[u][used] + w;
        pq.push(make_tuple(dist[v][used], v, used));
      }

      if (used == 0)
      {
        ll reduced = dist[u][0] + (w / 2);
        if (dist[v][1] > reduced)
        {
          dist[v][1] = reduced;
          pq.push(make_tuple(dist[v][1], v, 1));
        }
      }
    }
  }

  ll ans = dist[n][1];
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
