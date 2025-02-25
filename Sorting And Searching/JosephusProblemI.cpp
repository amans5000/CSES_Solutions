#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(ll n)
{
  queue<ll> q;
  for (int i = 1; i <= n; i++)
    q.push(i);

  bool flag = false;

  while (!q.empty())
  {
    int number = q.front();
    q.pop();
    if (flag)
    {
      cout << number << " ";
    }
    else
    {
      q.push(number);
    }
    flag = !flag;
  }
}

int main()
{
  ll n;
  cin >> n;
  solve(n);
}
