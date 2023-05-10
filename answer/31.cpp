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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        ListNode *p = head;
        int size = 0;
        while (p)
        {
            size++;
            p = p->next;
        }
        k = k % size;
        if (k == 0)
            return head;
        p = head;
        for (int i = 0; i < k; i++)
        {
            p = p->next;
        }
        ListNode *q = head;
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        p->next = head;
        p = q->next;
        q->next = nullptr;
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