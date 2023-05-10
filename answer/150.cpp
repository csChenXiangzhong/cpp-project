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
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        int n = tokens.size();
        int ans;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] == "+")
            {
                ans = s.top();
                s.pop();
                ans = s.top() + ans;
                s.pop();
                s.push(ans);
            }
            else if (tokens[i] == "-")
            {
                ans = s.top();
                s.pop();
                ans = s.top() - ans;
                s.pop();
                s.push(ans);
            }
            else if (tokens[i] == "*")
            {
                ans = s.top();
                s.pop();
                ans = s.top() * ans;
                s.pop();
                s.push(ans);
            }
            else if (tokens[i] == "/")
            {
                ans = s.top();
                s.pop();
                ans = s.top() / ans;
                s.pop();
                s.push(ans);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
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