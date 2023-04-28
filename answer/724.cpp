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
    int pivotIndex(vector<int> &nums)
    {
        int mid = -1;
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            rightSum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (leftSum == rightSum)
                return i;
            // 向后移，当i=i+1时的值
            leftSum += nums[i];
            if (i + 1 < nums.size())
                rightSum -= nums[i + 1];
        }
        // 上述循环已经判断完成，不应该再加以下语句。
        /*if (leftSum == rightSum)
            return nums.size() - 1;*/
        return -1;
    }
};
/*


*/
int main()
{

    Solution s1;
    string r;
    vector<int> nodes = {-1, -1, -1, 1, 1, 1};
    // BinaryTree *bt = new BinaryTree(nodes);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    s1.pivotIndex(nodes);
    // cout << s1.setZeroes(nodes) << endl;
    return 0;
}