#include <iostream>
using namespace std;

class Matrix
{
protected:
    int n;
    int *A;

    Matrix()
    {
        this->n = 2;
        A = new int(2);
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int(n);
    }
    ~Matrix()
    {
        delete[](A);
    }
};

class Diagonal : Matrix
{
public:
    Diagonal() : Matrix(){};

    Diagonal(int n) : Matrix(n){};

    // for diagonal Matrix
    void Set(int i, int j, int x)
    {
        if (i == j && i < n)
        {
            A[i] = x;
        }
    };

    // for diagonal Matrix
    int Get(int i, int j)
    {
        if (i == j && i < n)
            return A[i];
        else
            return 0;
    }

    // display it as 2D array
    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    printf("%d ", A[i]);
                else
                    printf("0 ");
            }
            printf("\n");
        }
    };
};

class LowerTriangularMatrixUsingRowMapping : Matrix
{

public:
    LowerTriangularMatrixUsingRowMapping() : Matrix(){};
    LowerTriangularMatrixUsingRowMapping(int n) : Matrix(n){};

    // for lower triangular matrix, using row mapping
    void Set(int i, int j, int x)
    {
        i = i + 1;
        j = j + 1;
        if (i >= j && i <= n && j <= n)
            A[(i * (i - 1)) / 2 + (i - j)] = x;
    }

    int Get(int i, int j)
    {
        i = i + 1;
        j = j + 1;
        if (i >= j && i <= n && j <= n)
            return A[(i * (i - 1)) / 2 + (i - j)];
        else
            return 0;
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                    printf("%d ", A[(i * (i - 1)) / 2 + (i - j)]);
                else
                    printf("%d ", 0);
            }
            printf("\n");
        }
    }
};

class LowerTriangularMatrixUsingColMapping : Matrix
{
public:
    LowerTriangularMatrixUsingColMapping() : Matrix(){};

    LowerTriangularMatrixUsingColMapping(int n) : Matrix(n){};
    // for lower triangular matrix using column mapping
    void Set(int i, int j, int x)
    {
        i += 1;
        j += 1;

        if (i >= j && i <= n && j <= n)
        {
            A[(n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)] = x;
        }
    };

    int Get(int i, int j, int x)
    {
        i += 1;
        j += 1;

        if (i >= j && i <= n && j <= n)
            return A[(n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)];
        else
            return 0;
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                    printf("%d  ", A[(n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)]);
                else
                    printf("%d  ", 0);
            }
            printf("\n");
        }
    }
};

class UpperTriangularMatrixUsingRowmapping : Matrix
{

public:
    UpperTriangularMatrixUsingRowmapping() : Matrix(){};
    UpperTriangularMatrixUsingRowmapping(int n) : Matrix(n){};

    void Set(int i, int j, int x)
    {
        i += 1;
        j += 1;
        if (j >= i && i <= n && j <= n)
        {
            A[(n * (i - 1)) - (((i - 2) * (i - 1)) / 2) + (j - i)] = x;
        }
    }

    int Get(int i, int j)
    {
        i += 1;
        j += 1;
        if (j >= i && i <= n && j <= n)
        {
            return A[(n * (i - 1)) - (((i - 2) * (i - 1)) / 2) + (j - i)];
        }
        else
        {
            return 0;
        }
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= i)
                    printf("%d ", A[(n * (i - 1)) - (((i - 2) * (i - 1)) / 2) + (j - i)]);
                else
                    printf("%d ", 0);
            }
            printf("\n");
        }
    }
};

class UpperTriangularMatrixUsingColMapping : Matrix
{
public:
    UpperTriangularMatrixUsingColMapping() : Matrix(){};

    UpperTriangularMatrixUsingColMapping(int n) : Matrix(n)
    {
        this->n;
        A = new int[n];
    };

    void Set(int i, int j, int x)
    {
        i += 1;
        j += 1;
        if (j >= i && i <= n && j <= n)
        {
            A[(j * (j - 1)) / 2 - (i - 1)] = x;
        }
    }

    int Get(int i, int j)
    {
        i += 1;
        j += 1;
        if (j >= i && i <= n && j <= n)
        {
            return A[(j * (j - 1)) / 2 - (i - 1)];
        }
        else
        {
            return 0;
        }
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= i)
                    printf("%d ", A[(j * (j - 1)) / 2 - (i - 1)]);
                else
                    printf("%d ", 0);
            }
            printf("\n");
        }
    }
};

class TriDiagonalMatrix : Matrix
{

public:
    TriDiagonalMatrix() : Matrix(){};
    TriDiagonalMatrix(int n) : Matrix(n){};
    void Set(int i, int j, int x)
    {
        i += 1;
        j += 1;

        if (i > n || j > n)
            return;

        if (i - j == 1)
            A[i - 2] = x;
        else if (i - j == 0)
            A[n + 1 + i - 1] = x;
        else if (i - j == -1)
            A[2 * (n - 1) + i] = x;
    }

    int Get(int i, int j, int x)
    {

        i += 1;
        j += 1;

        if (i - j == 1)
            return A[i - 2];
        else if (i - j == 0)
            return A[n + 1 + i - 1];
        else if (i - j == -1)
            return A[2 * (n - 1) + i];
        else
            return 0;
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i - j == 1)
                    printf("%d ", A[i - 2]);
                else if (i - j == 0)
                    printf("%d ", A[n + 1 + i - 1]);
                else if (i - j == -1)
                    printf("%d ", A[2 * (n - 1) + i]);
                else
                    printf("%d ", 0);
            }
            printf("\n");
        }
    }
};

class ToeplitxMatrix : Matrix
{
public:
    ToeplitxMatrix() : Matrix(){};

    ToeplitxMatrix(int n) : Matrix(n){};

    void Set(int i, int j, int x)
    {
        i += 1;
        j += 1;

        if (i > n || j > n)
            return;

        if (i - j < 1)
            A[j - i] = x;
        else if (i - j >= 1)
            A[n + i - j - 1] = x;
    }

    int Get(int i, int j)
    {
        i += 1;
        j += 1;

        if (i - j < 1)
            return A[j - i];
        else if (i - j >= 1)
            return A[n + i - j - 1];
        else
            return 0;
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i - j < 1)
                    printf("%d ", A[j - i]);
                else if (i - j >= 1)
                    printf("%d ", A[n + i - j - 1]);
                else
                    printf("%d ", 0);
            }
            printf("\n");
        }
    }
};

int main()
{

    Diagonal diagonal(5);

    diagonal.Set(0, 0, 1);
    diagonal.Set(0, 1, 0);
    diagonal.Set(0, 2, 0);
    diagonal.Set(0, 3, 0);
    diagonal.Set(0, 4, 0);

    diagonal.Set(1, 0, 0);
    diagonal.Set(1, 1, 1);
    diagonal.Set(1, 2, 0);
    diagonal.Set(1, 3, 0);
    diagonal.Set(1, 4, 0);

    diagonal.Set(2, 0, 0);
    diagonal.Set(2, 1, 0);
    diagonal.Set(2, 2, 1);
    diagonal.Set(2, 3, 0);
    diagonal.Set(2, 4, 0);

    diagonal.Set(3, 0, 0);
    diagonal.Set(3, 1, 0);
    diagonal.Set(3, 2, 0);
    diagonal.Set(3, 3, 1);
    diagonal.Set(3, 4, 0);

    diagonal.Set(4, 0, 0);
    diagonal.Set(4, 1, 0);
    diagonal.Set(4, 2, 0);
    diagonal.Set(4, 3, 0);
    diagonal.Set(4, 4, 1);

    diagonal.Display();
    return 0;
}