#include <stdio.h>

int calculate(int a, int b, char opr);

int main()
{
    int a;
    int b;
    char opr;

    printf("Type the first number: ");
    scanf("%d", &a);
    
    printf("Type the second number: ");
    scanf("%d", &b);

    printf("Type the operator (+, -, * or /): ");
    scanf(" %c", &opr);

    int result = calculate(a, b, opr);

    printf("Result: %d\n", result);

    return 0;
}

int calculate(int a, int b, char opr)
{
    switch(opr)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if(b != 0)
                return a / b;
            printf("error: dividing by zero\n");
            return 0;
        default:
            printf("error: invalid operator, use `+`, `-`, `*` or `/`\n");
    }
    return 0;
}