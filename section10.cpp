#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
public:
    int m;
    int n;
    int numOfElements;
    Element *e;

    Sparse(int m, int n, int numOfElements)
    {
        this->m = m;
        this->n = n;
        this->numOfElements = numOfElements;
    }

    void Read()
    {
        e = new Element[numOfElements];
        cout << "Enter i,j,x values" << endl;

        for (int i = 0; i < numOfElements; i++)
        {
            cin >> e[i].i;
            cin >> e[i].j;
            cin >> e[i].x;
            cout << endl;
        }
    }

    void Display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == e[k].i && j == e[k].j)
                {
                    cout << e[k].x;
                    cout << " ";
                    k++;
                }
                else
                {
                    cout << 0;
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    // instead of copying obejct B in function add, we will pass a pointer to b;
    Sparse *Add(Sparse *B)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        if (m != B->m || n != B->n)
        {
            cout << "Order of A and B should Be same"
                 << endl;
            return 0;
        }

        struct Sparse *C = (struct Sparse *)malloc(sizeof(struct Sparse));
        C->m = m;
        C->n = n;
        C->e = (struct Element *)malloc((numOfElements + B->numOfElements) * sizeof(struct Element));

        while (i < numOfElements && j < B->numOfElements)
        {
            if (e[i].i == B->e[j].i && e[i].j == B->e[j].j)
            {
                C->e[k] = e[i++];
                C->e[k++].x += B->e[j++].x;
            }
            else if (e[i].i == B->e[j].i && e[i].j > B->e[j].j)
                C->e[k++] = B->e[j++];
            else if (e[i].i == B->e[j].i && e[i].j < B->e[j].j)
                C->e[k++] = e[i++];
            else if (e[i].i > B->e[j].i)
                C->e[k++] = B->e[j++];
            else if (e[i].i < B->e[j].i)
                C->e[k++] = e[i++];
        }

        // COPY REMAINING ELEMENTS
        for (; i < numOfElements; i++)
        {
            C->e[k++] = e[i];
        }

        for (; j < B->numOfElements; j++)
        {
            C->e[k++] = B->e[j];
        }

        C->numOfElements = k;

        return C;
    };
};

int main()
{
    Sparse A(5, 6, 5);
    A.Read();
    cout << "Matrix A==" << endl;
    A.Display();

    Sparse B(5, 6, 6);
    B.Read();

    cout << "Matrix B==" << endl;
    B.Display();

    cout << "Matrix C==" << endl;
    Sparse *C = A.Add(&B);

    C->Display();
    return 0;
}