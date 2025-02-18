#include <bits/stdc++.h>
using namespace std;

void createStrings(string &s, string &current, int bitmask, int n, set<string> &permutations)
{
  if (current.length() == n)
  {
    permutations.insert(current);
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (!(bitmask & (1 << i)))
    {
      current.push_back(s[i]);
      createStrings(s, current, bitmask | (1 << i), n, permutations);
      current.pop_back();
    }
  }
}

int main()
{
  string s;
  cin >> s;

  string current = "";
  set<string> permutations;
  createStrings(s, current, 0, s.length(), permutations);
  cout << permutations.size() << endl;
  for (auto k : permutations)
  {
    cout << k << endl;
  }

  return 0;
}
