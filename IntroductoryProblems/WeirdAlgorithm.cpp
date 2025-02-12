#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << n << endl;
    int k = 5;
    while (n != 1 && k--)
    {
        if ((n & 1))
        {
            n = (3 * n) + 1;
        }
        else
        {
            n = n >> 1;
        }
        cout << n << endl;
    }
    return 0;
}
