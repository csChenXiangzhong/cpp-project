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
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }
            if (left < right)
            {
                if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                else
                {
                    left++;
                    right--;
                }
            }
        }
        return true;
    }
};
/*


*/
int main()
{

    Solution s1;
    string r;
    vector<int> nodes = {3, 2, 1, 5, 6, 4};
    // BinaryTree *bt = new BinaryTree(nodes);
    string sss = "aabaab!bb";
    cout << __cplusplus << endl;
    // s1.findKthLargest(nodes, 2);
    //  cout << s1.setZeroes(nodes) << endl;
    return 0;
}