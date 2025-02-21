#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }

  int longBook = *max_element(arr.begin(), arr.end());
  if (longBook >= sum - longBook)
  {
    cout << 2 * longBook;
  }
  else
  {
    cout << sum;
  }

  return 0;
}