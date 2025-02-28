#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> bfs(int n, unordered_map<int, vector<int>> &adj)
{
  vector<int> dist(n + 1, -1);
  vector<int> parent(n + 1, -1);
  queue<int> q;

  dist[1] = 0;
  q.push(1);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int neighbor : adj[node])
    {
      if (dist[neighbor] == -1)
      {
        dist[neighbor] = dist[node] + 1;
        parent[neighbor] = node;
        q.push(neighbor);
      }
    }
  }

  if (dist[n] == -1)
    return {};

  vector<int> path;
  for (int v = n; v != -1; v = parent[v])
    path.push_back(v);

  reverse(path.begin(), path.end());
  return path;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<int, vector<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> path = bfs(n, adj);

  if (path.empty())
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else
  {
    cout << path.size() << endl;
    for (int node : path)
    {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}
