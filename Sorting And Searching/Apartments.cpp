#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> app(n);
  vector<int> apt(m);

  for (int i = 0; i < n; i++)
  {
    cin >> app[i];
  }

  for (int i = 0; i < m; i++)
  {
    cin >> apt[i];
  }

  int ans = 0;

  sort(app.begin(), app.end());
  sort(apt.begin(), apt.end());

  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (app[i] <= (apt[j] + k))
    {
      if (app[i] >= (apt[j] - k))
      {
        i++;
        j++;
        ans++;
      }
      else
      {
        i++;
      }
    }
    else
    {
      j++;
    }
  }
  cout << ans;
  return 0;
}
