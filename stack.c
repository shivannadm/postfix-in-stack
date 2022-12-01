#include <stdio.h>

int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *expression;
    int op1, op2, result, symbol;
    printf("Enter the expression : ");
    scanf("%s", exp);
    expression = exp;
    while (*expression != '\0')
    {
        if (isdigit(*expression))
        {
            symbol = *expression - 48;
            push(symbol);
        }
        else
        {
            op1 = pop();
            op2 = pop();
            switch (*expression)
            {
            case '+':
            {
                result = op1 + op2;
                break;
            }
            case '-':
            {
                result = op2 - op1;
                break;
            }
            case '*':
            {
                result = op1 * op2;
                break;
            }
            case '/':
            {
                result = op2 / op1;
                break;
            }
            }
            push(result);
        }
        expression++;
    }
    printf("\nThe result of expression %s  =  %d\n\n", exp, pop());
    return 0;
}
