#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
{
  // Mark the current node as visited
  visited[node] = true;

  // Process all neighbors of the current node
  for (int neighbor : adj[node])
  {
    if (!visited[neighbor])
    {
      dfs(neighbor, visited, adj);
    }
  }
}

void solve(int n, int m, unordered_map<int, vector<int>> &adj)
{
  vector<bool> visited(n + 1, false);
  vector<pair<int, int>> ans;
  int prev = -1, curr = -1;
  for (int i = 1; i <= n; i++)
  {
    if (visited[i])
    {
      continue;
    }

    prev = curr;
    curr = i;
    if (prev != -1)
    {
      ans.push_back({prev, curr});
    }
    dfs(i, visited, adj);
  }
  cout << ans.size() << endl;
  for (auto t : ans)
  {
    cout << t.first << " " << t.second << endl;
  }
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

  solve(n, m, adj);
  return 0;
}
