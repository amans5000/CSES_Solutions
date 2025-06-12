#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  queue<pair<int, int>> q;
  pair<int, int> start;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (s[i][j] == 'M')
      {
        q.push({i, j});
      }
      if (s[i][j] == 'A')
      {
        start = {i, j};
      }
    }
  }
  q.push(start);

  while (!q.empty())
  {
    auto front = q.front();
    int x = front.first;
    int y = front.second;
    q.pop();

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> ch = {'U', 'D', 'L', 'R'};

    for (int i = 0; i < 4; i++)
    {
      int newX = x + dir[i].first;
      int newY = y + dir[i].second;

      if (newX >= 0 && newX < n && newY >= 0 && newY < m && s[newX][newY] == '.')
      {
        q.push({newX, newY});
        s[newX][newY] = (s[x][y] == 'M') ? 'M' : ch[i];
      }
    }
  }

  pair<int, int> end = {-1, -1};
  for (int i = 0; i < n; i++)
  {
    if (s[i][0] != 'M' && s[i][0] != '.' && s[i][0] != '#')
    {
      end.first = i;
      end.second = 0;
    }
    if (s[i][m - 1] != 'M' && s[i][m - 1] != '.' && s[i][m - 1] != '#')
    {
      end.first = i;
      end.second = m - 1;
    }
  }
  for (int i = 0; i < m; i++)
  {
    if (s[0][i] != 'M' && s[0][i] != '.' && s[0][i] != '#')
    {
      end.first = 0;
      end.second = i;
    }
    if (s[n - 1][i] != 'M' && s[n - 1][i] != '.' && s[n - 1][i] != '#')
    {
      end.first = n - 1;
      end.second = i;
    }
  }

  if (end.first == -1 || end.second == -1)
  {
    cout << "NO" << endl;
    return 0;
  }

  string res;

  cout << "YES" << endl;
  auto [x, y] = end;
  while (s[x][y] != 'A')
  {
    res += s[x][y];
    if (s[x][y] == 'R')
      y--;
    else if (s[x][y] == 'L')
      y++;
    else if (s[x][y] == 'D')
      x--;
    else
      x++;
  }
  cout << res.length() << endl;

  for (int i = res.length() - 1; i >= 0; i--)
  {
    cout << res[i];
  }

  return 0;
}