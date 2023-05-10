#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        quque.resize(k);
        front = -1;
        rear = -1;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front++;
        }
        rear = (rear + 1) % quque.size();
        quque[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return true;
        }
        front = (front + 1) % quque.size();

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return quque[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return quque[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear + 1) % quque.size() == front)
            return true;
        return false;
    }

private:
    vector<int> quque;
    int front;
    int rear;
};