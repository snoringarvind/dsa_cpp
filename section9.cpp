#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        this->n = 2;
        A = new int(2);
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int(n);
    }
    ~Diagonal()
    {
        delete[](A);
    }

    // for diagonal Matrix
    void Set(int i, int j, int x)
    {
        if (i == j && i < n)
        {
            A[i] = x;
        }
    }

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

class LowerTriangularMatrixUsingRowMapping
{
private:
    int *A;
    int n;

public:
    LowerTriangularMatrixUsingRowMapping()
    {
        n = 2;
        A = new int[n];
    };
    LowerTriangularMatrixUsingRowMapping(int n)
    {
        this->n = n;
        A = new int[n];
    };

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

class LowerTriangularMatrixUsingColMapping
{
private:
    int *A;
    int n;

public:
    LowerTriangularMatrixUsingColMapping()
    {
        n = 2;
        A = new int[n];
    };

    LowerTriangularMatrixUsingColMapping(int n)
    {
        this->n = n;
        A = new int[n];
    }
    // for lower triangular matrix using column mapping
    void Set(int i, int j, int x)
    {
        i += 1;
        j += 1;

        if (i >= j && i <= n && j <= n)
        {
            A[(n * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j)] = x;
        }
    }

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

class UpperTriangularMatrixUsingRowmapping
{
private:
    int *A;
    int n;

public:
    UpperTriangularMatrixUsingRowmapping()
    {
        n = 2;
        A = new int[n];
    };
    UpperTriangularMatrixUsingRowmapping(int n)
    {
        this->n = n;
        A = new int[n];
    }

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

class UpperTriangularMatrixUsingColMapping
{
private:
    int *A;
    int n;

public:
    UpperTriangularMatrixUsingColMapping()
    {
        n = 2;
        A = new int[n];
    }

    UpperTriangularMatrixUsingColMapping(int n)
    {
        this->n;
        A = new int[n];
    }

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

class TriDiagonalMatrix
{
private:
    int n;
    int *A;

public:
    TriDiagonalMatrix()
    {
        n = 2;
        A = new int[n];
    }
    TriDiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
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

class ToeplitxMatrix
{
private:
    int n;
    int *A;

public:
    ToeplitxMatrix()
    {
        n = 2;
        A = new int[n];
    }

    ToeplitxMatrix(int n)
    {
        this->n = n;
        A = new int[n];
    }

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

    ToeplitxMatrix toeplitzMatrix(5);

    toeplitzMatrix.Set(0, 0, 1);
    toeplitzMatrix.Set(1, 1, 1);
    toeplitzMatrix.Set(4, 4, 1);
    toeplitzMatrix.Set(2, 2, 1);

    toeplitzMatrix.Set(0, 1, 2);
    toeplitzMatrix.Set(0, 2, 3);
    toeplitzMatrix.Set(0, 3, 4);
    toeplitzMatrix.Set(0, 4, 5);

    toeplitzMatrix.Set(1, 0, 6);

    toeplitzMatrix.Set(1, 2, 2);
    toeplitzMatrix.Set(1, 3, 3);
    toeplitzMatrix.Set(1, 4, 4);

    toeplitzMatrix.Set(2, 0, 7);
    toeplitzMatrix.Set(2, 1, 6);
    toeplitzMatrix.Set(2, 3, 2);
    toeplitzMatrix.Set(2, 4, 3);

    toeplitzMatrix.Set(3, 0, 8);
    toeplitzMatrix.Set(3, 1, 7);
    toeplitzMatrix.Set(3, 2, 6);
    toeplitzMatrix.Set(3, 3, 1);
    toeplitzMatrix.Set(3, 4, 2);

    toeplitzMatrix.Set(4, 0, 9);
    toeplitzMatrix.Set(4, 1, 8);
    toeplitzMatrix.Set(4, 2, 7);
    toeplitzMatrix.Set(4, 3, 6);

    toeplitzMatrix.Display();
    return 0;
}