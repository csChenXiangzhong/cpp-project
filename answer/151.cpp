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
    string reverseWords(string s)
    {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        // idx表示已经整理好的序列的末尾
        int idx = 0;
        // start表示循环的原始序列的位置
        for (int start = 0; start < n; start++)
        {
            // 当start不为空格则开始操作，为空格则start++
            if (s[start] != ' ')
            {
                // 填一个空格并将idx移到下一个单词开头位置
                if (idx != 0)
                    s[idx++] = ' ';

                // 循环遍历值单词末尾
                int end = start;
                while (end < n && s[end] != ' ')
                {
                    s[idx++] = s[end++];
                }
                // 结束时end指向单词结尾的后一个位置
                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，找下一个单词
                start = end;
            }
        }
        // 去除末尾多余字符
        s.erase(s.begin() + idx, s.end());
        return s;
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

    // BinaryTree *bt = new BinaryTree(nodes);
    // s1.longestPalindrome(r);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}