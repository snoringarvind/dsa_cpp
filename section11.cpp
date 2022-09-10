#include <stdlib.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    class Node *Next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }

    LinkedList(int A[], int n)
    {
        Node *last, *p;
        first = new Node[sizeof(Node)];
        first->Data = A[0];
        first->Next = NULL;
        last = first;

        for (int i = 1; i < n; i++)
        {
            p = new Node[sizeof(Node)];
            p->Data = A[i];
            p->Next = NULL;

            last->Next = p;
            last = p;
        }
    }

    ~LinkedList()
    {
        Node *p;
        while (first != NULL)
        {
            p = first;
            first = first->Next;
            delete[](p);
        }
    }

    void Display()
    {
        Node *p = first;
        while (p != NULL)
        {
            cout << p->Data << " ";
            p = p->Next;
        }
        cout << endl;
    }

    int Count()
    {
        Node *p = first;
        int c = 0;
        while (p != NULL)
        {
            c++;
            p = p->Next;
        }

        return c;
    }

    int Max()
    {
        int max = INT_MIN;
        Node *p;
        while (p != NULL)
        {
            if (p->Data > max)
                max = p->Data;
            p = p->Next;
        }
        return max;
    }

    Node *Search(int element)
    {
        Node *p = first;
        while (p != NULL)
        {
            if (p->Data == element)
                return p;
            p = p->Next;
        }
        return NULL;
    }

    void Insert(int index, int x)
    {
        struct Node *t, *p;
        p = first;
        int i;

        if (index < 0 || index > Count())
            return;
        t = new Node[sizeof(Node)];
        t->Data = x;

        if (index == 0)
        {
            t->Next = p;
            p = t;
        }
        else
        {
            for (i = 0; i < index - 1; i++)
                p = p->Next;
            t->Next = p->Next;
            p->Next = t;
        }
    }

    int Delete(int index)
    {
        Node *q = NULL;
        Node *p = first;
        int x = -1;

        if (index < 0 || index > Count())
        {
            return x;
        }

        if (index == 0)
        {
            first = p->Next;
            x = p->Data;
            free(p);
        }
        else
        {
            int i = 0;
            for (i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->Next;
            }

            x = p->Data;
            q->Next = p->Next;

            free(p);
        }
        return x;
    }

    int isSorted()
    {
        Node *p = first;
        int min = INT_MIN;

        while (p != NULL)
        {
            if (p->Data < min)
            {
                return 0;
            }
            min = p->Data;
            p = p->Next;
        }
        return 1;
    }

    void RemoveDuplicates()
    {
        Node *p = first;
        Node *q = p->Next;
        while (q != NULL)
        {
            if (p->Data == q->Data)
            {
                p->Next = q->Next;
                free(q);
                q = p->Next;
            }
            else
            {
                p = q;
                q = q->Next;
            }
        }
    }

    // using pointers
    void Reverse()
    {
        Node *p = first;
        Node *q = NULL;
        Node *r = NULL;

        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->Next;

            q->Next = r;
        }
        first = q;
    }

    void Concatenate(Node *A, Node *B)
    {
        while (A->Next != NULL)
        {
            A = A->Next;
        }

        A->Next = B;
    }

    struct Node *Merge(struct Node *first, struct Node *second)
    {
        struct Node *third, *last;

        if (first->Data < second->Data)
        {
            third = last = first;
            first = first->Next;
            last->Next = NULL;
        }
        else
        {
            third = last = second;
            second = second->Next;
            last->Next = NULL;
        }

        while (first != NULL && second != NULL)
        {
            if (first->Data > second->Data)
            {
                last->Next = second;
                last = second;
                second = second->Next;
                last->Next = NULL;
            }
            else
            {
                last->Next = first;
                last = first;
                first = first->Next;
                last->Next = NULL;
            }
        }

        if (first != NULL)
            last->Next = first;
        else
            last->Next = second;
        return third;
    }

    int CheckLoop()
    {
        Node *p = first;
        Node *q = p;

        do
        {
            p = p->Next;
            q = q->Next;
            q = q != NULL ? q->Next : NULL;
        } while (p && q && p != q);

        if (p == q)
            return 1;
        else
            return 0;
    }
};

int main()
{
    int A[] = {5, 6, 7, 8, 9};
    LinkedList l(A, 5);
    l.Display();
    l.~LinkedList();
    l.Display();
}