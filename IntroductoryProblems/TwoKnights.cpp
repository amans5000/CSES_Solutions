#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  for (int k = 1; k <= n; k++)
  {
    long totalWays = ((long)k * k * (k * k - 1)) / 2;
    long attackingWays = 4 * (k - 1) * (k - 2);
    long ans = totalWays - attackingWays;
    cout << ans;
  }

  return 0;
}