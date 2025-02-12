#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  vector<int> pos(n);

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    arr[i] = temp - 1;
    pos[arr[i]] = i;   
  }

  int segments = 1;
  for (int i = 1; i < n; i++)
  {
    if (pos[i] < pos[i - 1]) 
    {
      segments++;
    }
  }

  while (m--)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;

    int idx1 = pos[a], idx2 = pos[b];
    swap(pos[a], pos[b]);
    swap(arr[idx1], arr[idx2]);

    // Update segment count efficiently
    set<int> to_check = {a, b};
    for (int x : to_check)
    {
      if (x > 0)
      {
        if (pos[x] < pos[x - 1])
          segments++;
        else
          segments--;
      }
      if (x < n - 1)
      {
        if (pos[x + 1] < pos[x])
          segments++;
        else
          segments--;
      }
    }

    cout << segments << endl;
  }

  return 0;
}
