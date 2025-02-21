#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> arr;
  for (int i = 0; i < n; i++)
  {
    int a, d;
    cin >> a >> d;
    arr.push_back({{a}, {d}, {i}});
  }

  sort(arr.begin(), arr.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rooms; //min-heap

  vector<int> roomsAssigned(n);
  int maxRooms = 0;

  for (auto &cus : arr)
  {
    if (!rooms.empty() && rooms.top().first < cus[0])
    {
      int roomNumber = rooms.top().second;
      rooms.pop();
      rooms.push({cus[1], roomNumber});
      roomsAssigned[cus[2]] = roomNumber;
    }
    else
    {
      int roomNumber = rooms.size() + 1;
      rooms.push({cus[1], roomNumber});
      roomsAssigned[cus[2]] = roomNumber;
      maxRooms = max(maxRooms, (int)rooms.size());
    }
  }

  cout << maxRooms << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << roomsAssigned[i] << " ";
  }
  cout << "\n";

  return 0;
}
