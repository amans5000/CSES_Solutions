#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {

    if (node == nullptr)
      return nullptr;

    Node *rootNode = new Node(node->val);
    queue<Node *> q;
    unordered_map<Node *, Node *> visited;
    q.push(node);

    while (!q.empty())
    {
      Node *tempNode = q.front();
      q.pop();
      visited.push_back(tempNode);

      for (auto k : tempNode->neighbors)
      {
        q.push(k);
      }
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}
