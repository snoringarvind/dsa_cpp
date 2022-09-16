#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};

class StackUsingLL
{
private:
    Node *Top;

public:
    StackUsingLL()
    {
        Top = NULL;
    }

    void Push(int x)
    {

        Node *p = new Node[sizeof(Node)];

        if (p == NULL)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            p->data = x;
            p->next = Top == NULL ? NULL : Top;
            Top = p;
        }
    };

    void Display()
    {
        Node *p = Top;

        while (p != NULL)
        {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }

    int Pop()
    {
        Node *q = Top;
        int x = -1;

        if (Top == NULL)
            cout << "stack underflow" << endl;
        else
        {
            x = Top->data;
            Top = q->next;
            free(q);
            q = NULL;
        }

        return x;
    }
};

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

    void Display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << S[i];
        }
        cout << endl;
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

    int IsEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
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

int GetStringLength(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
        i++;

    return i;
};

// infix to postfix
class InfixToPostfix
{
private:
    char *exp;

    int GetOutStackPrecedence(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 3;
        else if (x == '^')
            return 6;
        else if (x == '(')
            return 7;
        else if (x == ')')
            return 0;
        return 0;
    };

    int GetInStackPrecedence(char x)
    {
        if (x == '+' || x == '-')
            return 2;
        else if (x == '*' || x == '/')
            return 4;
        else if (x == '^')
            return 5;
        else if (x == '(')
            return 0;
        return 0;
    };

    int GetPrecedence(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        return 0;
    }

    int checkOperand(char x)
    {
        if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == '(' || x == ')')
            return 0;
        else
            return 1;
    };

    double calc(int a, char operand, int b)
    {
        double c = 0;
        cout << "in switch " << operand << endl;
        switch (operand)
        {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '*':
            c = a * b;
            break;
        case '/':
            cout << c << endl;
            c = a / b;
            cout << c << endl;
            break;
        case '^':
            c = pow(a, b);
            break;
        default:
            c = 0;
        }

        return c;
    };

public:
    InfixToPostfix()
    {
        exp = NULL;
    };
    InfixToPostfix(char *exp)
    {
        this->exp = exp;
    }

    // check parenthesis matching
    int isBalance(char *exp)
    {
        map<char, char> mapping;

        mapping[']'] = '[';
        mapping[')'] = '(';
        mapping['}'] = '{';

        map<char, char>::iterator itr;

        int length = GetStringLength(exp);

        StackUsingArray<char> St(length);

        for (int i = 0; i < length; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                St.Push(exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (St.IsEmpty())
                    return 0;
                else
                {
                    int temp = St.StackTop();
                    itr = mapping.find(exp[i]);

                    if (temp == itr->second)
                        St.Pop();
                    else
                        return 0;
                }
            }
        }

        if (St.IsEmpty())
            return 1;
        else
            return 0;

        return 0;
    };
    // infix to postfix without associativity
    char *Convert_withoutAssoc()
    {
        int length = GetStringLength(exp);
        StackUsingArray<char> St(length);

        // length +1 for '\0';
        char *postfix = new char[(length + 1) * sizeof(int)];

        int i = 0;
        int j = 0;
        while (exp[i] != '\0')
        {
            if (checkOperand(exp[i]))
            {
                postfix[j++] = exp[i];
                i++;
            }
            else
            {
                if (St.IsEmpty() || GetPrecedence(exp[i]) > GetPrecedence(St.StackTop()))
                {
                    St.Push(exp[i]);
                    i++;
                }
                else
                {
                    postfix[j++] = St.Pop();
                }
            }
        };

        while (!St.IsEmpty())
        {
            postfix[j++] = St.Pop();
        };

        postfix[j++] = '\0';

        return postfix;
    };

    // infix to postfix with associativity
    char *Convert_withAssoc()
    {
        int length = GetStringLength(exp);
        StackUsingArray<char> St(length);

        // length +1 for '\0';
        char *postfix = new char[(length + 1) * sizeof(int)];

        int i = 0;
        int j = 0;
        while (exp[i] != '\0')
        {
            if (checkOperand(exp[i]))
            {
                postfix[j++] = exp[i];
                i++;
            }
            else
            {
                if (St.IsEmpty() || GetOutStackPrecedence(exp[i]) > GetInStackPrecedence(St.StackTop()))
                {
                    St.Push(exp[i]);
                    i++;
                }
                else
                {
                    if (St.StackTop() == '(' && exp[i] == ')')
                    {
                        St.Pop();
                        i++;
                    }
                    else
                        postfix[j++] = St.Pop();
                }
            }
        };

        while (!St.IsEmpty())
        {
            postfix[j++] = St.Pop();
        };

        postfix[j++] = '\0';

        return postfix;
    }

    void DisplayPostfixExp(char *postfixExp)
    {
        int i = 0;
        while (postfixExp[i] != '\0')
        {
            cout << postfixExp[i];
            i++;
        }
        cout << endl;
    };

    // evaluate postfix expression
    double Eval(char *postfixExp)
    {
        int length = GetStringLength(postfixExp);
        StackUsingArray<double> St(length);

        int i = 0;
        while (postfixExp[i] != '\0')
        {
            if (checkOperand(postfixExp[i]))
            {
                St.Push(postfixExp[i++] - '0');
            }
            else
            {
                double b = St.Pop();
                double a = St.Pop();
                double c = calc(a, postfixExp[i], b);
                St.Push(c);
                i++;
            }
        }

        return St.StackTop();
    };
};

int main()
{
    char exp[] = "3*5+6/2-4";

    InfixToPostfix Infi(exp);

    char *postfix = Infi.Convert_withAssoc();

    Infi.DisplayPostfixExp(postfix);

    double x = Infi.Eval(postfix);
    cout << x;

    return 0;
}