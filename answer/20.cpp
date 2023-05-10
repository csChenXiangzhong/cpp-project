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
    bool isValid(string s)
    {
        stack<char> sc;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                sc.push(s[i]);
            else if (!sc.empty())
            {
                if ((s[i] == ')' && sc.top() == '(') || (s[i] == ']' && sc.top() == '[') || (s[i] == '}' && sc.top() == '{'))
                    sc.pop();
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
        return sc.empty();
    }
};

/*


*/
int main()
{
    Solution s;
    s.isValid("()");
    string r = "ccc";
    vector<string> nodes = {"flower", "flow", "flight"};
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    string sss = "aabaab!bb";

    sort(nums.begin(), nums.end());
    return 0;
}