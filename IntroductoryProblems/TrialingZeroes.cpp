#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n;
  cin >> n;

  int i = 1;
  int numzero = 0;
  int dividend = 1;

  while (dividend > 0)
  {
    dividend = n / pow(5, i++);
    numzero += dividend;
  }
  cout << numzero;
  return 0;
}
