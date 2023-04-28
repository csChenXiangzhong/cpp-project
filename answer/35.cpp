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

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        return searahInsertHelper(nums, target, 0, nums.size() - 1);
    }

    int searahInsertHelper(vector<int> &nums, int target, int left, int right)
    {
        // 中心或中心偏左
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (left == right)
            if (nums[left] < target)
                return left + 1;
            else
                return left;
        else if (nums[mid] < target)
            return searahInsertHelper(nums, target, min(mid + 1, right), right);
        else
            return searahInsertHelper(nums, target, left, max(left, mid - 1));
    }
};
/*


*/
int main()
{

    Solution s1;
    string r;
    vector<int> nodes = {1, 3};
    // BinaryTree *bt = new BinaryTree(nodes);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    s1.searchInsert(nodes, 0);
    // cout << s1.setZeroes(nodes) << endl;
    return 0;
}