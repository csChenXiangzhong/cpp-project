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
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return head;
        flattenHelper(head);
        return head;
    }
    // 返回最后一个节点
    Node *flattenHelper(Node *head)
    {
        Node *p = head;
        Node *prev;
        while (p != nullptr && p->child == nullptr)
        {
            prev = p;
            p = p->next;
        }
        if (p == nullptr)
            return prev;

        Node *cur = p->next;
        p->next = p->child;
        p->child->prev = p;
        p->child = nullptr;
        // 此处返回child的尾节点
        p = flattenHelper(p->next);
        p->next = cur;
        if (cur != nullptr)
        {
            cur->prev = p;
            p = flattenHelper(cur);
        }
        return p;
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