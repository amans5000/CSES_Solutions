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

  if (n == 1)
  {
    cout << arr[0];
    return 0;
  }

  long long i = 0, j = 0, maxSum = INT_MIN;
  long long sum = arr[0];

  while (i < n - 1 && j < n - 1)
  {
    if (sum < 0)
    {
      i++;
      j = i;
      sum = arr[i];
    }
    else
    {
      j++;
      sum += arr[j];
    }
    maxSum = max(maxSum, sum);
  }
  cout << maxSum << endl;
  return 0;
}
