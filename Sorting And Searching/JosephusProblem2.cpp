#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n, int k)
{
  vector<vector<int>> arr; // take 2D array of n x sqrt(n)

  int root = sqrt(n);
  int row = 0, col = 0, count = 0;

  vector<int> v;
  for (int i = 1; i <= n; i++) // break the array into smaller arrays after sqrt(n) elements and removing the sqrt(n)th element.
  {
    if (count > root)
    {
      count = 0;
      arr.push_back(v);
      v.clear();
    }
    v.push_back(i);
    count++;
  }
  if (!v.empty())
    arr.push_back(v);

  for (int i = 0; i < n; i++) // Stimulate the Josephus Process
  {
    int j = k % (n - i);

    while (j) // move the j-th element
    {
      if (col + j < arr[row].size())
      {
        col += j;
        j = 0;
      }
      else
      {
        j -= arr[row].size() - col;
        col = 0;
        row++;
      }
      if (row >= arr.size())
        row = 0;
    }

    while (arr[row].size() <= col)
    {
      col = 0;
      row++;
      if (row >= arr.size())
        row = 0;
    }
    cout << arr[row][col] << " "; // Print and Remove the Selected Element
    if (i != n - 1)
    {
      arr[row].erase(arr[row].begin() + col);

      while (arr[row].size() <= col) // Adjust Position After Removal
      {
        col = 0;
        row++;
        if (row >= arr.size())
          row = 0;
      }
    }
  }
}

int main()
{
  int n, k;
  cin >> n >> k;

  solve(n, k);

  return 0;
}
