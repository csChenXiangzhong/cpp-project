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
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> m;
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *newNode = new Node(head->val);
        m[head] = newNode;
        newNode->next = copyRandomList(head->next);
        // 由于上方代码递归将head链表中所有节点都复制了并放入了哈希表中，因此m[head->random]一定存在。
        if (head->random != nullptr)
            newNode->random = m[head->random];
        return newNode;
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