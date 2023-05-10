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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head = new ListNode(0);
        // p的下一个节点为需要计算的节点
        ListNode *p = head;
        int val = 0;
        // 先让两个链表能对上的部分相加
        while (l1 && l2)
        {
            if (val > 9)
            {
                val = l1->val + l2->val + 1;
            }
            else
            {
                val = l1->val + l2->val;
            }
            ListNode *node = new ListNode(val > 9 ? val - 10 : val);
            p->next = node;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // 不能对上的部分先连接起来
        if (l1 == nullptr)
        {
            p->next = l2;
        }
        else if (l2 == nullptr)
        {
            p->next = l1;
        }
        // 如果上次相加存在进位且没到链表末尾,此时p的下一个节点为需要计算的节点
        while (p->next != nullptr && val > 9)
        {
            val = 1 + p->next->val;
            p->next->val = val > 9 ? val - 10 : val;
            p = p->next;
        }
        // 如果到链表末尾且存在进位
        if (val > 9)
        {
            ListNode *node = new ListNode(1);
            p->next = node;
        }
        return head->next;
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