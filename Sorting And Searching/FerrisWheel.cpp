#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> weight(n);

  for (int i = 0; i < n; i++)
  {
    cin >> weight[i];
  }

  int i = 0, j = n - 1;
  int count = 0;
  while (weight[j] >= x)
  {
    j--;
    count++;
  }

  sort(weight.begin(), weight.end());

  while (i <= j)
  {
    if (weight[i] + weight[j] <= x)
    {
      i++;
      j--;
    }
    else
    {
      j--;
    }
    count++;
  }
  cout << count;
  return 0;
}
