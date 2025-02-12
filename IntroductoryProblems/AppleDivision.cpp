#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll calculate(int index, vector<ll> &arr, ll sum1, ll sum2, ll n)
{
  if (index == n)
  {
    return abs(sum1 - sum2);
  }

  ll choose = calculate(index + 1, arr, sum1 + arr[index], sum2, n);
  ll notChoose = calculate(index + 1, arr, sum1, sum2 + arr[index], n);

  return min(choose, notChoose);
  
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  ll ans = calculate(0, arr, 0, 0, n);
  cout << ans;
}
