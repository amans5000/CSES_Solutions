#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  if (n < 1)
  {
    cout << n;
    return 0;
  }

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  if (arr[0] != 1)
  {
    cout << 1;
    return 0;
  }

  long long sum = arr[0] + 1;

  for (int i = 1; i < n; i++)
  {
    if (arr[i] <= sum)
    {
      sum += arr[i];
    }
    else
    {
      cout << sum;
      return 0;
    }
  }
  cout << sum;

  return 0;
}