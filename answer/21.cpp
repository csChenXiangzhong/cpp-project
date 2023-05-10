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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        if (list1 == nullptr)
        {
            p->next = list2;
        }
        else if (list2 == nullptr)
        {
            p->next = list1;
        }
        return dummy->next;
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