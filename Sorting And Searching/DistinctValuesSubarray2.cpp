#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll subarraysLessOrEqual(vector<ll> &nums, ll k)
{
  ll l = 0, r = 0;
  ll n = nums.size();
  ll ans = 0;
  map<ll, ll> m;
  while (r < n)
  {
    m[nums[r]]++;
    if (m.size() <= k)
    {
      ans += r - l + 1;
      r++;
    }
    else
    {
      while (m.size() > k)
      {
        m[nums[l]]--;
        if (m[nums[l]] == 0)
          m.erase(nums[l]);
        l++;
      }
      ans += r - l + 1;
      r++;
    }
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, r;
  cin >> n >> r;
  vector<ll> arr(n);

  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << subarraysLessOrEqual(arr, r);

  return 0;
}
