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
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

/*


*/
int main()
{

    Solution s1;
    string r = "ccc";
    vector<string> nodes = {"flower", "flow", "flight"};
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> a;
    a[0] = 1;
    // BinaryTree *bt = new BinaryTree(nodes);
    // s1.longestPalindrome(r);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}