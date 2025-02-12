#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  vector<long long> stick(n);

  for (int i = 0; i < n; i++)
  {
    cin >> stick[i];
  }

  sort(stick.begin(), stick.end());
  int median = n / 2;

  long long x = 0;
  for (auto l : stick)
  {
    x += abs(l - stick[median]);
  }
  cout << x << endl;

  return 0;
}
