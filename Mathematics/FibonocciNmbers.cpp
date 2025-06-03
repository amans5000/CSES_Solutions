#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> matrixMultiply(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
  vector<vector<ll>> c(2, vector<ll>(2));
  c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
  c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
  c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
  c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
  return c;
}

vector<vector<long long>> mat_pow(const vector<vector<long long>> &T, long long n)
{
  vector<vector<long long>> result = {{1, 0}, {0, 1}};
  vector<vector<long long>> base = T;

  while (n > 0)
  {
    if (n % 2 == 1)
    {
      result = matrixMultiply(result, base);
    }
    base = matrixMultiply(base, base);
    n /= 2;
  }

  return result;
}

ll calculateMatrix(int n)
{
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll ans;

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to perform matrix exponentiation

// Function to calculate the nth Fibonacci number
long long fib(long long n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  // The transformation matrix T
  vector<vector<long long>> T = {{1, 1}, {1, 0}};

  // Perform matrix exponentiation to get T^(n-1)
  vector<vector<long long>> result = mat_pow(T, n - 1);

  // The nth Fibonacci number is located at result[0][0]
  return result[0][0];
}

int main()
{
  long long n;
  cout << "Enter the value of n: ";
  cin >> n;

  cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;

  return 0;
}
