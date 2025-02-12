#include <bits/stdc++.h>
using namespace std;

int main()
{
  int testcases;
  cin >> testcases;
  while (testcases--)
  {
    int l, r;
    cin >> l >> r;

    if ((l == 0 && r != 0) || (l > 2 * r) || (r > (2 * l)))
    {
      cout << "NO" << endl;
      continue;
    }

    l = l % 3;
    r = r % 3;
    if ((l == 1 && r == 2) || (l == 2 && r == 1) || (l == r && l == 0))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}
