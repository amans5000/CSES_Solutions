#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() // Dijkstra's algorithm for directed graph from node 1
{
  ll n, m;
  cin >> n >> m;

  vector<vector<pair<ll, ll>>> adj(n + 1); // 1-indexed adjacency list

  for (ll i = 0LL; i < m; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<ll> dist(n + 1, LLONG_MAX);
  dist[1] = 0LL; // distance from node 1

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0LL, 1}); // {distance, node}

  while (!pq.empty())
  {
    auto top = pq.top();
    ll distance = top.first;
    ll node = top.second;
    pq.pop();

    if (distance > dist[node])
      continue;

    for (auto &[nextNode, edgeWeight] : adj[node])
    {
      if (distance + edgeWeight < dist[nextNode])
      {
        dist[nextNode] = distance + edgeWeight;
        pq.push({dist[nextNode], nextNode});
      }
    }
  }

  for (ll i = 1; i <= n; i++)
  {
    if (dist[i] == LLONG_MAX)
      cout << -1 << " ";
    else
      cout << dist[i] << " ";
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
