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
    int openLock(vector<string> &deadends, string target)
    {
        if (target == "0000")
            return 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;
        // 返回类型后置语法，即尾置返回类型
        // 向前传轮盘
        auto num_prev = [](char x) -> char
        {
            return (x == '0' ? '9' : x - 1);
        };
        // 向后转轮盘
        auto num_succ = [](char x) -> char
        {
            return (x == '9' ? '0' : x + 1);
        };
        // 枚举status通过一次旋转得到的数字,&用于按引用访问所有动态变量
        auto get = [&](string &status) -> vector<string>
        {
            vector<string> ret;
            for (int i = 0; i < 4; i++)
            {
                char num = status[i];
                status[i] = num_prev(num);
                ret.push_back(status);
                status[i] = num_succ(num);
                ret.push_back(status);
                status[i] = num;
            }
            return ret;
        };
        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = {"0000"};
        while (!q.empty())
        {
            auto [status, step] = q.front();
            q.pop();
            // && 表示右值引用
            for (auto &&next_status : get(status))
            {
                if (!seen.count(next_status) && !dead.count(next_status))
                {
                    if (next_status == target)
                    {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    // move告诉编译器：我们有一个左值，但我们希望像一个右值一样处理它。提高效率。
                    seen.insert(move(next_status));
                }
            }
        }
        return -1;
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