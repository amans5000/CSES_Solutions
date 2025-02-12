#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  if (n < 3)
  {
    cout << "NO";
    return 0;
  }

  vector<int> arr1;
  vector<int> arr2;
  int triflag;
  bool inv = 0;
  int sum1 = 0, sum2 = 0;

  if (n % 2 == 0)
  {
    triflag = 2;
  }
  else
  {
    triflag = 1;
  }

  for (int i = 1; i <= n; i++)
  {
    triflag = (triflag + 1) % 2;
    if (!triflag)
    {
      inv = !inv;
    }
    if (inv)
    {
      arr1.push_back(i);
      sum1 += i;
    }
    else
    {
      arr2.push_back(i);
      sum2 += i;
    }
  }

  if (sum1 != sum2)
  {
    cout << "NO";
  }
  else
  {
    cout << "YES" << endl;
    cout << arr1.size() << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
      cout << arr1[i] << " ";
    }
    cout << endl;
    cout << arr2.size() << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
      cout << arr2[i] << " ";
    }
  }

  return 0;
}
