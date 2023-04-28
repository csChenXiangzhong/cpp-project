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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 1;
        int n = nums.size();
        int numSum = nums[0];
        int minLen = INT_MAX;
        while (right <= n)
        {
            if (numSum < target && right != n)
            {

                numSum += nums[right++];
            }
            else if (numSum < target && right == n)
            {
                right++;
            }
            else if (numSum >= target)
            {
                minLen = min(minLen, right - left);
                numSum -= nums[left++];
            }
        }
        /*if (numSum >= target)
            return min(minLen, right - left);*/

        return minLen == INT_MAX ? 0 : minLen;
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

    // BinaryTree *bt = new BinaryTree(nodes);
    // s1.longestPalindrome(r);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}