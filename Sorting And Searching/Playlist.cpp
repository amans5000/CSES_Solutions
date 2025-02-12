#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i; i < n; i++)
  {
    cin >> arr[i];
  }

  int i = 0, ans = 0;
  map<int, int> mp;
  for (int j = 0; j < n; j++)
  {
    if (mp.find(arr[j]) == mp.end())
      mp.insert({arr[j], j});
    else
    {
      if (mp[arr[j]] >= i)
        i = mp[arr[j]] + 1;
      mp[arr[j]] = j;
    }
    ans = max(ans, j - i + 1);
  }

  cout << ans << "\n";
}
