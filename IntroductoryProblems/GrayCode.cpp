#include <bits/stdc++.h>
using namespace std;

void permute(int index, string &s)
{
  if (index == -1)
  {
    cout << s << endl;
    return;
  }

  permute(index - 1, s);

  s[index] == '1' ? s[index] = '0' : s[index] = '1';

  permute(index - 1, s);
}

int main()
{
  int n;
  cin >> n;
  string s(n, '0');

  permute(n - 1, s);

  return 0;
}
