#include <bits/stdc++.h>
#define ll long long
using namespace std;

void floydWarshall(ll n, vector<vector<ll>> &dist)
{
  for (ll k = 1; k <= n; k++)
  {
    for (ll i = 1; i <= n; i++)
    {
      for (ll j = 1; j <= n; j++)
      {
        if (dist[i][k] < 1e15 && dist[k][j] < 1e15)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, t;
  cin >> n >> m >> t;

  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e15));

  for (ll i = 0LL; i < m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }

  for (ll i = 1; i <= n; i++)
  {
    dist[i][i] = 0;
  }

  floydWarshall(n, dist);

  while (t--)
  {
    int a, b;
    cin >> a >> b;
    cout << ((dist[a][b] >= 1e15) ? -1 : dist[a][b]) << endl;
  }
  return 0;
}
