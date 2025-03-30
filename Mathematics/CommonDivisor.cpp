#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> freq(1e6 + 1, 0);

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    if (temp <= 1e6)
      freq[temp]++;
  }

  for (int i = 1e6; i > 0; i--)
  {
    int count = 0;
    for (int j = i; j <= 1e6; j += i)
    {
      count += freq[j];
      if (count >= 2)
      {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}
