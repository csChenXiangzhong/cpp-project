#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int S = (right - left) * min(height[left], height[right]);
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                int oleft = left;
                left++;
                while (left < right && height[left] < height[oleft])
                {
                    left++;
                }
                if (left < right)
                    S = max(S, (right - left) * min(height[left], height[right]));
            }
            else
            {
                int oright = right;
                right--;
                while (left < right && height[right] < height[oright])
                {
                    right--;
                }
                if (left < right)
                    S = max(S, (right - left) * min(height[left], height[right]));
            }
        }
        return S;
    }
};