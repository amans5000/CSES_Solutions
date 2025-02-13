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

  if (n <= 1)
  {
    cout << n;
    return 0;
  }

  vector<int> tower;

  for (int i = 0; i < arr.size(); i++)
  {
    auto index = upper_bound(tower.begin(), tower.end(), arr[i]);

    if (index == tower.end())
    {
      tower.push_back(arr[i]);
    }
    else
    {
      *index = arr[i];
    }
  }

  cout << tower.size();

  return 0;
}