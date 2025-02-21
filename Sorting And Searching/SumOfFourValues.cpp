#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  map<int, vector<int>> m;
  for (int i = 0; i < n; i++)
  {
    m[arr[i]].push_back(i + 1);
  }

  sort(arr.begin(), arr.end());

  for (int k = 0; k < n - 3; k++)
  {
    for (int j = k + 1; j < n - 2; j++)
    {
      ll target = x - arr[k] - arr[j];
      ll left = j + 1, right = n - 1;
      while (left < right)
      {
        ll sum = arr[left] + arr[right];
        if (sum == target)
        {
          cout << m[arr[k]].back() << " ";
          m[arr[k]].pop_back();
          cout << m[arr[j]].back() << " ";
          m[arr[j]].pop_back();
          cout << m[arr[left]].back() << " ";
          m[arr[left]].pop_back();
          cout << m[arr[right]].back();
          return 0;
        }
        else if (sum < target)
        {
          left++;
        }
        else
        {
          right--;
        }
      }
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}