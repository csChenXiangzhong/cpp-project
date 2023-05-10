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

// 单向链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    int get(int index)
    {
        if (index >= size)
        {
            return -1;
        }
        ListNode *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val)
    {
        ListNode *temp = new ListNode(val);
        temp->next = head;
        head = temp;
        size++;
        return;
    }

    void addAtTail(int val)
    {
        if (head == nullptr)
        {
            addAtHead(val);
            return;
        }
        ListNode *temp = new ListNode(val);
        ListNode *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
        size++;
        return;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        ListNode *temp = new ListNode(val);
        ListNode *p = head;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
        size++;
        return;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;

        ListNode *p = head;
        if (index == 0)
        {
            head = head->next;
            delete p;
            size--;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        ListNode *temp = p->next;
        p->next = p->next->next;
        delete temp;
        size--;
        return;
    }

private:
    int size;
    ListNode *head;
};

// 双向链表

struct DoublyListNode
{
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        size = 0;
        head = new DoublyListNode(0);
    }

    int get(int index)
    {
        if (index >= size)
            return -1;
        DoublyListNode *p = head;
        for (int i = 0; i <= index; i++)
        {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
        return;
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
        return;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        DoublyListNode *p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        DoublyListNode *addNode = new DoublyListNode(val);
        addNode->next = p->next;
        addNode->prev = p;
        if (p->next != nullptr)
            p->next->prev = addNode;
        p->next = addNode;
        size++;
        return;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        DoublyListNode *p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        // DoublyListNode *t = p->next;
        p->next = p->next->next;
        if (p->next != nullptr)
        {
            p->next->prev = p;
        }
        // delete t;
        size--;
        return;
    }

private:
    DoublyListNode *head;
    int size;
};

/*


*/
int main()
{

    // Solution s1;
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