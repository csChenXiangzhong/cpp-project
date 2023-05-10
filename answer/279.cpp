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
    unordered_set<int> m;
    int numSquares(int n)
    {
        for (int i = 1, j = i * i; j <= n; i++, j = i * i)
        {
            m.emplace(j);
        }
        for (int i = 1; i <= 4; i++)
        {
            if (numSquaresHelper(n, i))
            {
                return i;
            }
        }
        return 5;
    }
    bool numSquaresHelper(int n, int num)
    {
        if (num == 1)
            return m.count(n);
        for (const auto &x : m)
        {
            if (numSquaresHelper(n - x, num - 1))
            {
                return true;
            }
        }
        return false;
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