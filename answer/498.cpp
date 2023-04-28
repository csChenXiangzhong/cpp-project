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

// 此方法是方阵的对角线遍历。
class Solution1
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int d = 0;
        // 输出上三角
        for (; d < mat.size(); d++)
        {
            if (d % 2 == 0)
            {
                for (int i = d; i >= 0; i--)
                {
                    ans.push_back(mat[i][d - i]);
                }
            }
            else
            {
                for (int i = 0; i <= d; i++)
                {
                    ans.push_back(mat[i][d - i]);
                }
            }
        }
        // 输出下三角，不包含反对角线，令d=mat.size()-1。
        // 下三角最小的下标
        int sub = 1;
        for (; d <= 2 * (mat.size() - 1); d++)
        {
            if (d % 2 == 0)
            {
                for (int i = d / 2; i >= sub; i--)
                {
                    ans.push_back(mat[i][d - i]);
                }
                sub++;
            }
            else
            {
                for (int i = sub; i < d; i++)
                {
                    ans.push_back(mat[i][d - i]);
                }
                sub++;
            }
        }
        return ans;
    }
};

// 矩阵的对角线遍历
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> res;
        int m = mat.size(), n = mat[0].size();
        // i代表对角线的编号
        for (int i = 0; i < m + n - 1; i++)
        {
            // 从上往下遍历
            if (i % 2)
            {
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0)
                {
                    res.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            // 从下往上遍历
            else
            {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while (x >= 0 && y < n)
                {
                    res.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return res;
    }
};
/*


*/
int main()
{

    Solution s1;
    string r;
    vector<int> nodes = {1, 3};
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // BinaryTree *bt = new BinaryTree(nodes);
    s1.findDiagonalOrder(nums);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}