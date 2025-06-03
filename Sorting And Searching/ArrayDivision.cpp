#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPosible(vector<ll> &arr, ll mid, ll r)
{
  ll n = arr.size();
  ll setCount = 1;
  ll curSum = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] + curSum > mid)
    {
      if (setCount >= r)
        return false;
      setCount++;
      curSum = arr[i];
    }
    else
    {
      curSum += arr[i];
    }
  }
  return true;
}

void solve()
{
  ll n, r;
  cin >> n >> r;
  vector<ll> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  ll left = *max_element(arr.begin(), arr.end()), right = accumulate(arr.begin(), arr.end(), 0LL), ans = right;
  while (left <= right)
  {
    ll mid = left + (right - left) / 2;
    if (isPosible(arr, mid, r))
    {
      ans = mid;
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
