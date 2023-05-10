#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int left = 0, right = s.size() - 1;
        unordered_set<char> m = {'a', 'e', 'i', 'o', 'u'};
        while (left < right)
        {
            while (left < right && m.find(tolower(s[left])) == m.end())
            {
                left++;
            }
            while (left < right && m.find(tolower(s[right])) == m.end())
            {
                right--;
            }
            if (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};