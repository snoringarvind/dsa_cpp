#include <stdlib.h>
#include <iostream>
using namespace std;

template <class T>
class StackUsingArray

{
private:
    int top;
    int size;
    T *S;

public:
    StackUsingArray()
    {
        size = 1;
        top = -1;
        S = new T[size * sizeof(int)];
    };

    StackUsingArray(int x)
    {
        if (x > 0)
        {
            size = x;
            top = -1;
            S = new T[size * sizeof(int)];
        }
    };

    ~StackUsingArray()
    {
        delete[] S;
    }

    void Display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << S[i];
        }
        cout << endl;
    }

    int IsEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int IsFull()
    {
        if (top == size - 1)
            return 1;
        else
            return 0;
    }

    void Push(T x)
    {
        if (top == size - 1)
            cout << "stack overflow" << endl;
        else
            S[++top] = x;
    }

    int Pop()
    {
        int x = -1;

        if (top == -1)
            cout << "stack underflow" << endl;
        else
        {
            x = S[top];
            S[top--] = 0;
        }
        return x;
    }

    T StackTop()
    {
        // will return the Ascii if char type
        T x;

        if (top != -1)
        {
            x = S[top];
            return x;
        }
        else
            return -1;
    }
};

class Queue
{
private:
    StackUsingArray<int> *S1;
    StackUsingArray<int> *S2;

public:
    Queue(int size)
    {
        S1 = new StackUsingArray<int>(size);
        S2 = new StackUsingArray<int>(size);
    };

    ~Queue()
    {
        delete S1;
        delete S2;
    }

    void Enqueue(int x)
    {
        S1->Push(x);
    }

    int Dequeue()
    {
        int x = -1;
        if (S2->IsEmpty())
        {
            if (S1->IsEmpty())
            {
                printf("Queue is empty");
            }
            else
            {
                while (!S1->IsEmpty())
                {
                    S2->Push(S1->Pop());
                }
                x = S2->Pop();
            }
        }
        else
        {
            x = S2->Pop();
        }
        return x;
    }

    void Display()
    {
        while (!S2->IsEmpty())
        {
            printf("%d ", S2->Pop());
        }

        while (!S1->IsEmpty())
        {
            S2->Push(S1->Pop());
        }

        while (!S2->IsEmpty())
        {
            printf("%d ", S2->Pop());
        }

        printf("\n");
    }
};

int main()
{
    Queue Q(5);

    for (int i = 1; i <= 5; i++)
    {
        Q.Enqueue(i);
    }

    for (int i = 0; i < 2; i++)
    {
        Q.Dequeue();
    }

    Q.Display();

    Q.~Queue();

    return 0;
}