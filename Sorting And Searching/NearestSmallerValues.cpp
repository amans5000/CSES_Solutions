#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> res(n, 0);
  stack<int> s;

  for (int i = 0; i < n; i++)
  {
    while (!s.empty() && arr[s.top()] >= arr[i])
    {
      s.pop();
    }

    if (!s.empty())
    {
      res[i] = s.top() + 1;
    }

    s.push(i);
  }

  for (int i : res)
  {
    cout << i << " ";
  }

  return 0;
}
