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
  map<int, stack<int>> m;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    m[arr[i]].push(i + 1);
  }
  sort(arr.begin(), arr.end());

  for (ll j = 0; j < n - 2; j++)
  {
    ll target = x - arr[j];
    ll left = j + 1, right = n - 1;
    while (left < right)
    {
      ll sum = arr[left] + arr[right];
      if (sum == target)
      {
        cout << m[arr[right]].top() << " ";
        m[arr[right]].pop();
        cout << m[arr[left]].top() << " ";
        m[arr[left]].pop();
        cout << m[arr[j]].top();
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
  cout << "IMPOSSIBLE";
  return 0;
}