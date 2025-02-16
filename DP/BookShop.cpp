#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> pages(n);
  vector<int> prices(n);

  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> pages[i];
  }

  vector<int> prev(x + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    vector<int> curr(x + 1);
    for (int j = 0; j <= x; j++)
    {
      int include = (j >= prices[i - 1] ? prev[j - prices[i - 1]] + pages[i - 1] : 0);
      int exclude = prev[j];
      curr[j] = max(exclude, include);
    }
    prev = curr;
  }

  cout << prev[x] << endl;
  return 0;
}