#include <iostream>
#define MOD 1000000007
using namespace std;

long long calculate(long long base, long long n, long long mod)
{
  long long result = 1;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    n /= 2;
  }
  return result;
}

int main()
{
  long long n;
  cin >> n;
  cout << calculate(2, n, MOD) << endl;
  return 0;
}