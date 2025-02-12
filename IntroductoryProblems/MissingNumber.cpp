#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int count = 0;
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            sum += (arr[i] - count);
            count++;
        }
        return n - sum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int count = 0;
    int sum = 0;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += (arr[i] - count);
        count++;
    }

    cout << (n - sum);
    return 0;
}
