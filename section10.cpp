#include <iostream>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int numOfElements;
    struct Element *e;
};

int main()
{
    struct Sparse A;
    A.m = 5;
    A.n = 6;
    A.numOfElements = 5;
    A.e = new Element[A.numOfElements];

    struct Sparse B;
    B.m = 5;
    B.n = 6;
    B.numOfElements = 6;
    B.e = new Element[B.numOfElements];

    A.e[0].i = 1;
    A.e[0].j = 4;
    A.e[0].x = 6;

    A.e[1].i = 2;
    A.e[1].j = 2;
    A.e[1].x = 7;

    A.e[2].i = 3;
    A.e[2].j = 2;
    A.e[2].x = 2;

    A.e[3].i = 3;
    A.e[3].j = 4;
    A.e[3].x = 5;

    A.e[4].i = 5;
    A.e[4].j = 1;
    A.e[4].x = 4;

    B.e[0].i = 2;
    B.e[0].j = 2;
    B.e[0].x = 3;

    B.e[1].i = 2;
    B.e[1].j = 5;
    B.e[1].x = 5;

    B.e[2].i = 3;
    B.e[2].j = 3;
    B.e[2].x = 2;

    B.e[3].i = 3;
    B.e[3].j = 6;
    B.e[3].x = 7;

    B.e[4].i = 4;
    B.e[4].j = 4;
    B.e[4].x = 9;

    B.e[5].i = 5;
    B.e[5].j = 1;
    B.e[5].x = 8;

    struct Sparse C;
    C.m = 5;
    C.n = 6;
    C.numOfElements = A.numOfElements + B.numOfElements;
    C.e = new Element[C.numOfElements];

    int C_index_count = 0;

    int i = 0;
    int j = 0;

    while (i < A.numOfElements && j < B.numOfElements)
    {
        // printf("row A=>%d %d\n", A.e[i].i, A.e[i].j);
        // printf("row B=>%d %d\n", B.e[j].i, B.e[j].j);

        if (A.e[i].i == B.e[j].i && A.e[i].j == B.e[j].j)
        {
            C.e[C_index_count].i = A.e[i].i;
            C.e[C_index_count].j = A.e[i].j;
            C.e[C_index_count].x = A.e[i].x + B.e[j].x;

            printf("row C=>%d %d %d %d\n", C.e[C_index_count].i, C.e[C_index_count].j, C.e[C_index_count].x, C_index_count);
            i++;
            j++;
        }
        else if (A.e[i].i == B.e[j].i && A.e[i].j > B.e[j].j)
        {
            C.e[C_index_count].i = B.e[j].i;
            C.e[C_index_count].j = B.e[j].j;
            C.e[C_index_count].x = B.e[j].x;

            printf("row C=>%d %d %d %d\n", C.e[C_index_count].i, C.e[C_index_count].j, C.e[C_index_count].x, C_index_count);
            j++;
        }
        else if (A.e[i].i == B.e[j].i && A.e[i].j < B.e[j].j)
        {
            C.e[C_index_count].i = A.e[i].i;
            C.e[C_index_count].j = A.e[i].j;
            C.e[C_index_count].x = A.e[i].x;
            printf("row C=>%d %d %d %d\n", C.e[C_index_count].i, C.e[C_index_count].j, C.e[C_index_count].x, C_index_count);
            i++;
        }
        else if (A.e[i].i > B.e[j].i)
        {

            C.e[C_index_count].i = B.e[j].i;
            C.e[C_index_count].j = B.e[j].j;
            C.e[C_index_count].x = B.e[j].x;
            printf("row C=>%d %d %d %d\n", C.e[C_index_count].i, C.e[C_index_count].j, C.e[C_index_count].x, C_index_count);
            j++;
        }
        else if (A.e[i].i < B.e[j].i)
        {
            C.e[C_index_count].i = A.e[i].i;
            C.e[C_index_count].j = A.e[i].j;
            C.e[C_index_count].x = A.e[i].x;
            printf("row C=>%d %d %d %d\n", C.e[C_index_count].i, C.e[C_index_count].j, C.e[C_index_count].x, C_index_count);
            i++;
        }

        C_index_count++;
    }

    C.numOfElements = C_index_count;

    for (i = 0; i < C_index_count; i++)
    {
        printf("%d %d %d\n", C.e[i].i, C.e[i].j, C.e[i].x);
    }

    return 0;
}