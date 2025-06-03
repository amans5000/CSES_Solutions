#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  ll n, k;
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> lengths;

  for (int i = 0; i < k; i++)
  {
    int temp;
    cin >> temp;
    lengths.push(temp);
  }
  ll sum = 0LL;

  while (lengths.size() > 1)
  {
    int first = lengths.top();
    lengths.pop();
    int second = lengths.top();
    lengths.pop();
    lengths.push(first + second);
    sum += first + second;
  }

  cout << sum << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
