#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long n, target;
  cin >> n >> target;
  vector<long long> arr(n);

  for (long long i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  if (n < 2)
  {
    cout << "IMPOSSIBLE";
    return 0;
  }

  map<long long, long long> m;

  for (long long i = 0; i < n; i++)
  {
    long long comp = target - arr[i];
    if (m.find(comp) != m.end())
    {
      cout << m[comp] + 1 << " " << i + 1;
      return 0;
    }
    m[arr[i]] = i;
  }

  cout << "IMPOSSIBLE";
  return 0;
}
