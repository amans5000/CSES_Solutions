#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  unordered_map<char, int> m;
  for (char c : s)
  {
    m[c]++;
  }

  int odd_count = count_if(m.begin(), m.end(), [](const pair<char, int> &p)
                           { return p.second % 2 != 0; });

  if ((odd_count > 1) || (odd_count > 0 && s.length() % 2 == 0))
  {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  string left = "", right = "", mid = "";

  for (auto k : m)
  {
    if (k.second % 2 != 0)
    {
      mid = k.first;
    }

    string temp(k.second / 2, k.first);
    left += temp;
    right = temp + right;
  }

  cout << left + mid + right << endl;

  return 0;
}
