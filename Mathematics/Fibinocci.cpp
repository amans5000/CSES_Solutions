#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<ll>> matrixMultiply(const vector<vector<ll>> &m1, const vector<vector<ll>> &m2)
{
    vector<vector<ll>> result(2, vector<ll>(2));
    result[0][0] = (m1[0][0] * m2[0][0] % MOD + m1[0][1] * m2[1][0] % MOD) % MOD;
    result[0][1] = (m1[0][0] * m2[0][1] % MOD + m1[0][1] * m2[1][1] % MOD) % MOD;
    result[1][0] = (m1[1][0] * m2[0][0] % MOD + m1[1][1] * m2[1][0] % MOD) % MOD;
    result[1][1] = (m1[1][0] * m2[0][1] % MOD + m1[1][1] * m2[1][1] % MOD) % MOD;

    return result;
}

vector<vector<ll>> powerCalculate(vector<vector<ll>> &m, ll n)
{
    vector<vector<ll>> result = {{1, 0}, {0, 1}};

    while (n > 0)
    {
        if (n % 2 == 1)
            result = matrixMultiply(result, m);

        m = matrixMultiply(m, m);
        n /= 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<ll>> m = {{1, 1}, {1, 0}};
    m = powerCalculate(m, n - 1);

    cout << m[0][0] << endl;
    return 0;
}
