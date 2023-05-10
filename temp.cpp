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
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    grid[i][j] = '0';
                    DFS(grid, i - 1, j);
                    DFS(grid, i + 1, j);
                    DFS(grid, i, j - 1);
                    DFS(grid, i, j + 1);
                }
            }
        }
    }
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
            DFS(grid, i - 1, j);
            DFS(grid, i + 1, j);
            DFS(grid, i, j - 1);
            DFS(grid, i, j + 1);
        }
        return;
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