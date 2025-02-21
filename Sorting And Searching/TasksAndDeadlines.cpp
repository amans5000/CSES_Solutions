#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first;
    cin >> arr[i].second;
  }

  sort(arr.begin(), arr.end());

  ll ans = 0;
  ll time = 0;
  for (auto i : arr)
  {
    time = time + i.first;
    ans += (i.second - time);
  }

  cout << ans;

  return 0;
}
