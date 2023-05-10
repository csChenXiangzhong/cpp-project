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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
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