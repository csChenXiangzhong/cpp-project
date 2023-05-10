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
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int i = 1; i < rowIndex; i++)
        {
            // 1LL为long long类型，防止溢出。
            ans[i] = 1LL * ans[i - 1] * (rowIndex - i + 1) / i;
        }
        ans[rowIndex] = 1;
        return ans;
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