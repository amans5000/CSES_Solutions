#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() // using topological sort or khans algorithm also detect cycle if there
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> indegree(n + 1, 0);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
    indegree[u]++;
  }

  stack<int> ans;
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
    {
      indegree[i] = -1;
      q.push(i);
      ans.push(i);
    }
  }
  while (!q.empty())
  {
    auto top = q.front();
    q.pop();
    for (auto it : adj[top])
    {
      indegree[it]--;
      if (indegree[it] == 0)
      {
        indegree[it] = -1;
        q.push(it);
        ans.push(it);
      }
    }
  }

  if (ans.size() < n)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  while (!ans.empty())
  {
    cout << ans.top() << " ";
    ans.pop();
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
