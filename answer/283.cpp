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

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)
            return;
        int slow = 0, fast = 0;
        while(fast<nums.size())
        {
            while(fast<nums.size()&&nums[fast]==0)
            {
                fast++;
            }
            if(fast<nums.size()&&fast>slow)
            {
                swap(nums[slow++], nums[fast]);
            }
            else if(fast<nums.size()&&fast==slow)
            {
                fast++;
                slow++;
            }
        }
        return;
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