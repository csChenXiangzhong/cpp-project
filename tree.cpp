// 测试leetcode中树结构时的用例
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 构造一下二叉树
class BinaryTree
{
public:
    TreeNode *root; // 根节点

    /// <summary>
    /// BFS——根据数组构建二叉树
    /// 数组中节点的顺序表示的就是BFS的顺序
    /// 所以使用BFS 完成搜索
    /// </summary>au
    /// <param name="nodes"></param>
    BinaryTree(vector<string> nodes)
    {
        // 下标索引
        int i = 0;
        // 数组尺寸
        int n = nodes.size();
        // 先判断根节点是否是空
        if (nodes[0] == "null" && n == 1)
        {
            root = nullptr;
            return;
        }
        // 非空则新建根节点
        stringstream ss;
        ss << nodes[0];
        int val;
        ss >> val;
        root = new TreeNode(val);
        i++;
        // 节点对列
        queue<TreeNode *> que;
        // 先将根结点入队
        que.push(root);
        // 当对列不空且未遍历完时
        while (!que.empty() && i < n)
        {
            // 获取节点并出队
            TreeNode *node = que.front();
            que.pop();
            // 然后给左右指针
            for (int j = 1; j <= 2 && i < n; ++j, ++i)
            {
                // 若空则置空
                if (nodes[i] == "null" && j == 1)
                {
                    node->left == nullptr;
                }
                else if (nodes[i] == "null" && j == 2)
                {
                    node->right = nullptr;
                }
                // 非空则生成节点并入队
                else if (j == 1)
                {
                    node->left = new TreeNode(stoi(nodes[i]));
                    que.push(node->left);
                }
                else
                {
                    node->right = new TreeNode(stoi(nodes[i]));
                    que.push(node->right);
                }
            }
        }
    }

    /// <summary>
    /// 展示树的结构
    /// 为了能够清晰展示，还是使用BFS
    /// </summary>
    void display()
    {
        // 若根节点为空
        if (root == nullptr)
        {
            return;
        }
        // 非空入队
        queue<TreeNode *> que;
        que.push(root);
        // 每一层节点的数量，包括空节点
        int t = 0, num = 1;
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            cout << node->val << " ";
            num--;
            for (int i = 0; i < 2; ++i)
            {
                TreeNode *child;
                if (i == 0)
                {
                    child = node->left;
                }
                else
                {
                    child = node->right;
                }
                if (child != nullptr)
                {
                    que.push(child);
                    t++;
                }
            }
            // 当num = 0 时，说明当层遍历完，需要换行，进入下一层
            if (num == 0)
            {
                cout << endl;
                num = t;
                t = 0;
            }
        }
    }
};

class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return to_string(root->val);
        }
        else if (root->right == nullptr)
        {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        ans[0].push_back(1001);
        levelOrderHelper(root, ans, 0);
        ans.pop_back();
        return ans;
    }
    void levelOrderHelper(TreeNode *root, vector<vector<int>> &ans, int n)
    {
        if (!root)
        {
            return;
        }
        if (ans[n][0] == 1001)
        {
            ans.emplace(ans.end() - 1, vector<int>());
        }
        ans[n].push_back(root->val);
        levelOrderHelper(root->left, ans, n + 1);
        levelOrderHelper(root->right, ans, n + 1);
        return;
    }
};

/*


*/
int main()
{
    vector<string> nodes = {"3", "9", "20", "null", "null", "15", "7"};
    BinaryTree *bt = new BinaryTree(nodes);
    Solution s1;
    string r;
    s1.levelOrder(bt->root);
    cout << r << endl;
    return 0;
}