#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool detectCycle(int i, unordered_map<int, vector<int>> &mp, vector<bool> &visited, vector<int> &cycleNodes, int parent)
{
  visited[i] = true;
  cycleNodes.push_back(i);

  for (auto &k : mp[i])
  {
    if (!visited[k])
    {
      if (detectCycle(k, mp, visited, cycleNodes, i))
      {
        return true;
      }
    }
    else if (visited[k] && parent != k)
    {
      cycleNodes.push_back(k);
      return true;
    }
  }
  cycleNodes.pop_back();
  return false;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    mp[u].push_back(v);
    mp[v].push_back(u);
  }

  vector<bool> visited(n + 1, false);
  vector<int> cycleNodes;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && detectCycle(i, mp, visited, cycleNodes, -1))
    {
      reverse(cycleNodes.begin(), cycleNodes.end());
      while (cycleNodes.back() != cycleNodes[0])
      {
        cycleNodes.pop_back();
      }
      cout << cycleNodes.size() << endl;
      for (int j = 0; j < cycleNodes.size(); j++)
      {
        cout << cycleNodes[j] << " ";
      }
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
