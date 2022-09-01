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
private:
    int m;
    int n;
    int numOfElements;
    Element *e;

public:
    Sparse(int m, int n, int numOfElements)
    {
        this->m = m;
        this->n = n;
        this->numOfElements = numOfElements;
    }
    ~Sparse()
    {
        delete[] e;
    };

    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
    Sparse operator+(Sparse &B);
};

istream &operator>>(istream &is, Sparse &s)
{
    s.e = new Element[s.numOfElements];
    cout << "Enter i,j,x values" << endl;

    for (int i = 0; i < s.numOfElements; i++)
    {
        is >> s.e[i].i;
        is >> s.e[i].j;
        is >> s.e[i].x;
        cout << endl;
    }
    return is;
};

ostream &operator<<(ostream &os, Sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                cout << s.e[k].x;
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
    return os;
};

Sparse Sparse::operator+(Sparse &B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (m != B.m || n != B.n)
    {
        cout << "Order of A and B should Be same"
             << endl;
        // return 0;
    }

    struct Sparse *C = (struct Sparse *)malloc(sizeof(struct Sparse));
    C->m = m;
    C->n = n;
    C->e = (struct Element *)malloc((numOfElements + B.numOfElements) * sizeof(struct Element));

    while (i < numOfElements && j < B.numOfElements)
    {
        if (e[i].i == B.e[j].i && e[i].j == B.e[j].j)
        {
            C->e[k] = e[i++];
            C->e[k++].x += B.e[j++].x;
        }
        else if (e[i].i == B.e[j].i && e[i].j > B.e[j].j)
            C->e[k++] = B.e[j++];
        else if (e[i].i == B.e[j].i && e[i].j < B.e[j].j)
            C->e[k++] = e[i++];
        else if (e[i].i > B.e[j].i)
            C->e[k++] = B.e[j++];
        else if (e[i].i < B.e[j].i)
            C->e[k++] = e[i++];
    }

    // COPY REMAINING ELEMENTS
    for (; i < numOfElements; i++)
    {
        C->e[k++] = e[i];
    }

    for (; j < B.numOfElements; j++)
    {
        C->e[k++] = B.e[j];
    }

    C->numOfElements = k;

    return *C;
};

int main()
{
    Sparse A(5, 6, 5);
    cin >> A;
    cout << "Matrix A==" << endl;
    cout << A;

    Sparse B(5, 6, 6);
    cin >> B;
    cout << "Matrix B==" << endl;
    cout << B;

    cout << "Matrix C==" << endl;
    Sparse C = A + B;
    cout << C;

    return 0;
}