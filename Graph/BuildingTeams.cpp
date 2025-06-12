#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool bfs(int node, unordered_map<int, vector<int>> &friends, vector<int> &visited, int n)
{
  queue<int> q;
  visited[node] = 1;
  q.push(node);

  while (!q.empty())
  {
    int current = q.front();
    int color = visited[current];
    q.pop();

    for (auto &neighbor : friends[current])
    {
      if (visited[neighbor] == 0)
      {
        visited[neighbor] = color == 1 ? 2 : 1;
        q.push(neighbor);
      }
      else if (visited[neighbor] == color)
      {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
      else
      {
        continue; // Already visited with a different color
      }
    }
  }
  return 1;
}

void solve()
{
  int n, f;
  cin >> n >> f;
  unordered_map<int, vector<int>> friends;
  for (int i = 0; i < f; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    friends[a].push_back(b);
    friends[b].push_back(a);
  }
  vector<int> visited(n, 0);

  for (int i = 0; i < n; i++)
  {
    if (visited[i] != 0)
      continue;
    if (!bfs(i, friends, visited, n))
    {
      return;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << visited[i] << " ";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
