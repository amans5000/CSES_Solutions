#include <bits/stdc++.h>
using namespace std;

int dfs(unordered_map<int, vector<int>> &m, int index, vector<int> &dp)
{
  int count = 0;
  for (int child : m[index])
  {
    if (dp[child] == -1)
    {
      dp[child] = dfs(m, child, dp);
    }
    count += 1 + dp[child];
  }
  return count;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  unordered_map<int, vector<int>> m;

  for (int i = 0; i < n - 1; ++i)
  {
    int parent;
    cin >> parent;
    m[parent].push_back(i + 2);
  }

  vector<int> dp(n + 1, -1);

  dp[1] = dfs(m, 1, dp);

  for (int i = 1; i <= n; i++)
  {
    cout << dp[i] << " ";
  }
  cout << endl;

  return 0;
}
