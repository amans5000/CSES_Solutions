#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string n;
  cin >> n;

  int maxCount = 1;
  int count = 1;
  for (int i = 1; i < n.length(); i++)
  {
    if (n[i] == n[i - 1])
    {
      count++;
      maxCount = max(maxCount, count);
    }
    else
      count = 1;
  }
  if (maxCount == 0)
  {
    maxCount = 1;
  }
  cout << maxCount;

  return 0;
}
