#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int i = 0, j = 0;
  ll sum = 0;
  int count = 0;

  while (j < n)
  {
    sum += arr[j];
    while (sum > target)
    {
      sum -= arr[i];
      i++;
    }
    if (sum == target)
    {
      count++;
    }
    j++;
  }

  cout << count << endl;
  return 0;
}
