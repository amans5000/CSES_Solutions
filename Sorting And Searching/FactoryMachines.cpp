#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPossible(vector<int> &machines, int t, ll mid)
{
  ll count = 0;
  for (auto i : machines)
  {
    int temp = mid / i;
    count += temp;
  }
  return count >= t;
}

int main()
{
  int n, t;
  cin >> n >> t;

  vector<int> machines(n);

  for (int i = 0; i < n; i++)
  {
    cin >> machines[i];
  }

  ll left = 1;
  ll right = (ll)t * (*min_element(machines.begin(), machines.end()));
  ll ans = right;

  while (left <= right)
  {
    ll mid = left + (right - left) / 2;
    if (isPossible(machines, t, mid))
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

  return 0;
}
