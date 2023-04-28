#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // next[j]表示第j位前的子串的最大重复子串的长度
    void getNext(vector<int> &next, string needle)
    {
        next[0] = -1;
        // j为next数组中指向的当前位置
        int j = 0;
        // k为j前的字符串的最大重复子串的长度
        int k = -1;
        while (j < next.size() - 1)
        {
            if (k == -1 || needle[j] == needle[k])
            {
                j++;
                k++;
                // 当needle[++j]与needle[++k]相同时，
                // 说明：当主串haystack[i]与模式串needle[j]不匹配时，若在needle中有needle[j] == needle[k]，则原串haystack[i]
                // 与模式串needle[k]也必定不匹配，因此此处使得next[j] = next[k]，即next[j]位移长度为needle[k]的最大重复子串的
                // 长度。
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
    }
    int strStr(string haystack, string needle)
    {
        vector<int> next(needle.size());
        this->getNext(next, needle);
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
                cout << (-1 < needle.size()) << endl;
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
    int x = 123;
    Solution s1;
    cout << s1.strStr("hello", "ll")
         << endl;
    return 0;
}