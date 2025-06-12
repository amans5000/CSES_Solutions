#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(vector<vector<char>> &grid, pair<int, int> node, vector<vector<ll>> &dist, vector<char> &ans, int n, int m)
{
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  char dir[] = {'U', 'R', 'D', 'L'};

  queue<pair<int, int>> q;
  q.push(node);

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (grid[x][y] == 'B')
    {
      cout << "YES" << endl;
      cout << dist[x][y] << endl;
      string path = "";
      while (x != node.first || y != node.second)
      {
        for (int i = 0; i < 4; i++)
        {
          int prevX = x - dx[i];
          int prevY = y - dy[i];

          if (prevX >= 0 && prevX < n && prevY >= 0 && prevY < m &&
              dist[prevX][prevY] == dist[x][y] - 1)
          {
            path += dir[i];
            x = prevX;
            y = prevY;
            break;
          }
        }
      }
      reverse(path.begin(), path.end());
      cout << path << endl;
      exit(0);
    }

    for (int i = 0; i < 4; i++)
    {
      int newX = x + dx[i];
      int newY = y + dy[i];

      if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
          grid[newX][newY] != '#' && dist[newX][newY] > dist[x][y] + 1)
      {
        dist[newX][newY] = dist[x][y] + 1;
        q.push({newX, newY});
      }
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  pair<int, int> start;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
      {
        start = {i, j};
      }
    }
  }

  vector<char> ans;
  vector<vector<ll>> dist(n, vector<ll>(m, 1e9));
  dist[start.first][start.second] = 0;
  bfs(grid, start, dist, ans, n, m);
  cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
