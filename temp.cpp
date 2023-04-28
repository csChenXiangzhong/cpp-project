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
    vector<int> getNext(string needle)
    {
        vector<int> next(needle.size());
        next[0] = -1;
        // j指向next数组中当前位置
        int j = 0;
        // k指向j前的字符串的最长公共前缀后缀的长度
        int k = -1;
        while (j < next.size() - 1)
        {
            if (k == -1 || needle[j] == needle[k])
            {
                j++;
                k++;
                // 当needle[++j]与needle[++k]相同时，
                // 说明：当主串haystack[i]与模式串needle[j]不匹配时，若在needle中有needle[j] == needle[k]，则原串haystack[i]
                // 与模式串needle[k]也必定不匹配，因此此处使得next[j] = next[k]，即next[j]位移长度为needle[k]的最大公共前缀后
                // 缀的长度。
                if (needle[j] == needle[k])
                {
                    next[j] = next[k];
                }
                else
                { // 当其不相同时，直接令next[j]为最长重复子串的长度。
                    next[j] = k;
                }
            }
            else
            { // 如果needle[j]!=needle[k]，则说明需要再从needle[k]的最长重复子串的位置开始，再次查找j的最长重复子串
                k = next[k];
            }
        }
        return next;
    }
    int strStr(string haystack, string needle)
    {
        vector<int> next = getNext(needle);
        // 主串
        int i = 0;
        // 模式串
        int j = 0;
        // 注意此处needle.size()的类型是string
        while (i < haystack.size() && j < int(needle.size()))
        {
            if (j == -1 || haystack[i] == needle[j])
            { // 相等或j==-1时将两个指针都后移
                i++;
                j++;
            }
            else
            { // 当不相等时将j指向needle[j]最大不重复子串的位置，i位置不变
                j = next[j];
                // cout << (-1 < needle.size()) << endl;
            }
        }
        if (j == needle.size())
        {
            return i - j;
        }
        else
            return -1;
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
    vector<int> a;
    a[0] = 1;
    // BinaryTree *bt = new BinaryTree(nodes);
    // s1.longestPalindrome(r);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.searchInsert(nodes, 0);
    //  cout << s1.setZeroes(nodes) << endl;
    sort(nums.begin(), nums.end());
    return 0;
}