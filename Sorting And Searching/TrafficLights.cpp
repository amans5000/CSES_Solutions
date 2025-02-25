#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;

  set<int> s;
  multiset<int> m;
  vector<int> signal(x);

  s.insert(0);
  s.insert(n);
  m.insert(n);

  for (int i = 0; i < x; i++)
  {
    cin >> signal[i];
    s.insert(signal[i]);

    auto it = s.find(signal[i]);
    int nextNo = *next(it);
    int prevNo = *prev(it);

    auto pos = m.find(nextNo - prevNo);
    if (pos != m.end())
      m.erase(pos);

    m.insert(nextNo - signal[i]);
    m.insert(signal[i] - prevNo);

    cout << *m.rbegin() << " ";
  }

  return 0;
}
