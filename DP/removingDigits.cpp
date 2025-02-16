#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll calculate(int n)
{
  if (n < 10)
  {
    return 1;
  }

  int x = n;
  int maxDigit = 0;
  while (x > 0)
  {
    int digit = x % 10;
    maxDigit = max(maxDigit, digit);
    x /= 10;
  }

  return (1 + calculate(n - maxDigit));
}

int main()
{
  int n;
  cin >> n;

  vector<ll> dp(n + 1, -1);
  dp[0] = 0;

  ll result = calculate(n);

  if (result == -1)
    cout << -1;
  else
    cout << result;

  return 0;
}
