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
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    int quickSelect(vector<int> &nums, int left, int right, int k)
    {
        int q = randomPartition(nums, left, right);
        if (q + 1 == k)
        {
            return nums[q];
        }
        else if (k < q + 1)
        {
            return quickSelect(nums, left, q - 1, k);
        }
        else
        {
            return quickSelect(nums, q + 1, right, k);
        }
    }
    int randomPartition(vector<int> &nums, int left, int right)
    {
        // 取随机数
        int r = rand() % (right - left + 1) + left;
        swap(nums[r], nums[left]);
        int mid = nums[left];
        int i = left, j = right;
        while (i < j)
        {
            // 从右向左移动到不小于mid的值
            while (i < j && nums[j] < mid)
            {
                j--;
            }
            if (i < j)
            {
                swap(nums[i++], nums[j]);
            }
            // 从左向右移动到小于mid的值
            while (i < j && nums[i] >= mid)
            {
                i++;
            }
            if (i < j)
            {
                swap(nums[i], nums[j--]);
            }
        }
        return i;
    }
};

/*


*/
int main()
{

    Solution s1;
    string r;
    vector<int> nodes = {3, 2, 1, 5, 6, 4};
    // BinaryTree *bt = new BinaryTree(nodes);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    s1.findKthLargest(nodes, 2);
    // cout << s1.setZeroes(nodes) << endl;
    return 0;
}