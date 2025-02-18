#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &board, int row,
           vector<bool> &column,
           vector<bool> &first,
           vector<bool> &second, int &ans)
{
  if (row == 8)
  {
    ans += 1;
    return;
  }
  
  for (int col = 0; col < 8; col++)
  {
    if (board[row][col] == '*' || column[col] || first[row - col + 8] || second[row + col])
    {
      continue;
    }
    column[col] = first[row - col + 8] = second[row + col] = true;
    solve(board, row + 1, column, first,
          second, ans);
    column[col] = first[row - col + 8] = second[row + col] = false;
  }
}

int main()
{
  vector<string> board(8);
  for (int i = 0; i < 8; i++)
  {
    cin >> board[i];
  }
  vector<bool> column(8, false);
  vector<bool> first(16, false);
  vector<bool> second(16, false);

  int ans = 0;
  solve(board, 0, column, first,
        second, ans);
  cout << ans << "\n";
}
