#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> ans;
  ans.push_back(arr[0]);

  for (int i = 1; i < n; i++)
  {
    auto it = find_if(ans.begin(), ans.end(), [num = arr[i]](int a)
                      { return a < num; });

    if (it != ans.end())
    {
      *it = arr[i];
    }
    else
    {
      ans.push_back(arr[i]);
    }
  }

  cout << ans.size();
  return 0;
}
