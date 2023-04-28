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
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        for (int j = 0; j < strs[0].size(); j++)
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[0][j] != strs[i][j])
                    return ans;
            }
            ans += strs[0][j];
        }
        return ans;
    }
};