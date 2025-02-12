#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  multiset<int> ticketPrice;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    ticketPrice.insert(temp);
  }

  for (int i = 0; i < m; i++)
  {
    int temp;
    cin >> temp;

    auto it = ticketPrice.upper_bound(temp);

    if (it == ticketPrice.begin())
    {
      cout << -1 << endl;
    }
    else
    {
      --it;
      cout << *it << endl;
      ticketPrice.erase(it);
    }
  }

  return 0;
}
