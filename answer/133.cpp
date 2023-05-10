#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <list>
#include <stack>
#include <sstream>
#include <cmath>
#include <map>
#include <time.h>
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
    unordered_map<int, Node *> m;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        if (m.count(node->val))
            return m[node->val];
        Node *newnode = new Node(node->val);
        m.emplace(newnode->val, newnode);
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            Node *neighbor = cloneGraph(node->neighbors[i]);
            newnode->neighbors.push_back(neighbor);
            // neighbor->neighbors.push_back(newnode);
        }
        return newnode;
    }
};
/*


*/
int main()
{

    string r = "ccc";
    vector<string> nodes = {"flower", "flow", "flight"};
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    string sss = "aabaab!bb";

    sort(nums.begin(), nums.end());
    return 0;
}