#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b)
       {
         if (a.second == b.second)
           return a.first < b.first; 
         return a.second < b.second; });

  int ans = 0;
  int currEnd = -1;

  for (auto movie : arr)
  {
    if (movie.first >= currEnd)
    {
      ans++;
      currEnd = movie.second;
    }
  }

  cout << ans << endl;

  return 0;
}
