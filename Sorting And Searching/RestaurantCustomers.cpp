#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> events;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    events.push_back({temp, 1}); // start time
    cin >> temp;
    events.push_back({temp, -1}); // end time
  }

  sort(events.begin(), events.end(), [](pair<int, int> a, pair<int, int> b)
       {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first; });

  int maxCount = 0, currentCount = 0;

  int currTime = -1;

  for (auto event : events)
  {
    if (event.first > currTime)
    {
      if (event.second == 1)
      {
        currentCount++;
      }

      else if (event.second == -1)
      {
        currentCount--;
      }
    }
    else
    {
      continue;
    }

    maxCount = max(maxCount, currentCount);
  }

  cout << maxCount << endl;

  return 0;
}
