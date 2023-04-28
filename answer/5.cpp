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
    string longestPalindrome(string s)
    {
        string ans = "";
        int maxLength = 0;
        int mleft = 0, mright = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int left1 = i - 1, right1 = i + 1;
            while (left1 >= 0 && right1 < s.size() && s[left1] == s[right1])
            {
                left1--;
                right1++;
            }
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < s.size() && s[left2] == s[right2])
            {
                left2--;
                right2++;
            }
            if (right1 >= right2 && maxLength < (right1 - left1 - 1))
            {
                maxLength = right1 - left1 - 1;
                mleft = left1 + 1;
                mright = right1;
            }
            else if (right1 < right2 && maxLength < (right2 - left2 - 1))
            {
                maxLength = right2 - left2 - 1;
                mleft = left2 + 1;
                mright = right2;
            }
        }
        ans.assign(s.begin() + mleft, s.begin() + mright);
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

    // BinaryTree *bt = new BinaryTree(nodes);
    s1.longestPalindrome(r);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}