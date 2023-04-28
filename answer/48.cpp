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
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++)
                swap(matrix[i][j], matrix[i][n - j - 1]);
        return;
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
    s1.rotate(nums);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}