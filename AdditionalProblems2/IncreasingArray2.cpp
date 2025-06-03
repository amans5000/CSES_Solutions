#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;

  priority_queue<int> q;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    q.push(temp);

    ll top = q.top();
    q.pop();

    ans += top - temp;

    q.push(temp);
  }
  cout << ans << endl;
  return 0;
}