#include <bits/stdc++.h>
using namespace std;

int dfs(unordered_map<int, vector<int>> &m, int index)
{
  
  return 0;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  unordered_map<int, vector<int>> adj;

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> leafNodes;
  for (int i = 1; i <= n; i++)
  {
    if (adj[i].size() == 1)
    {
      leafNodes.push_back(i);
    }
  }

  for (auto i : leafNodes)
  {
    int maxDist = dist(i);
  }

  return 0;
}
