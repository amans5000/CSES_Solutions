#include <bits/stdc++.h>
using namespace std;

void Hanoi(int n, int a, int b, int c)
{
  if (n == 1)
  {
    cout << a << " " << b << endl;
    return;
  }

  Hanoi(n - 1, a, c, b);
  cout << a << " " << b << endl;
  Hanoi(n - 1, c, b, a);
}

int HanoiCount(int n, int a, int b, int c)
{
  if (n == 1)
  {
    return 1;
  }

  int upper = HanoiCount(n - 1, a, c, b);
  int lower = HanoiCount(n - 1, c, b, a);
  return upper + lower + 1;
}

int main()
{

  int n;
  cin >> n;

  if (n < 2)
  {
    cout << n << endl;
    if (n == 1)
    {
      cout << 1 << " " << 3 << endl;
    }
    return 0;
  }

  cout << HanoiCount(n, 1, 3, 2) << endl;
  Hanoi(n, 1, 3, 2);

  return 0;
}
