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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            if (merged.empty() || merged.back()[1] < l)
                merged.push_back({l, r});
            else
                merged.back()[1] = max(merged.back()[1], r);
        }
        return merged;
    }
};
/*


*/
int main()
{

    Solution s1;
    string r;
    vector<int> nodes = {1, 3};
    vector<vector<int>> nums = {{2, 6}, {1, 3}, {1, 2}};
    // BinaryTree *bt = new BinaryTree(nodes);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}