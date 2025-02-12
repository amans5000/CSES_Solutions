#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  long long increment = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] < arr[i - 1])
    {
      increment += arr[i - 1] - arr[i];
      arr[i] = arr[i - 1];
    }
  }

  cout << increment;

  return 0;
}