#include <stdio.h>
#include <string.h>
#include <conio.h>

/* Global Declarations */
int pos = 0;
int top;
int length;
char symbol;
char temp;
char s[30];
char infix;
char prefix;

void push(char sym)
{
    top = top + 1;
    s[top] = sym;
}

char pop()
{
    char item;
    item = s[top];
    top = top - 1;
    return item;
}

int G(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case ')':
        return 9;
    default:
        return 7;
    }
}
int F(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

void infix_prefix(char infix[], char prefix[])
{
    int i, t1;
    top = -1;
    length = strlen(infix);
    expression * /
        length = length - 1;
    pos = length;
    t1 = length;

    while (length >= 0)
    {
        symbol = infix[length];
        switch (symbol)
        {

        case ')':
            push(symbol);
            break;

        case '(':
            temp = pop();
            while (temp != ')')
            {
                prefix[pos] = temp;
                pos--;
                temp = pop();
            }
            if (temp != ')')
            {
                prefix[pos--] = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '$':
        case '/':
        case '^':
            while (F(s[top]) >= G(symbol))
            {
                temp = pop();
                prefix[pos] = temp;
                pos--;
            }
            push(symbol);
            break;
        default:
            prefix[pos--] = symbol;
            break;
        }
        length--;
        {
            while (s[] != '#')
            {
                temp = pop();
                prefix[pos--] = temp;
            }
            for (i = 0; i < t1; i++)
            {
                prefix[i] = prefix[i + pos + 1];
            }
            /* MAIN PROGRAM */
            void main()
            {

                printf("Enter the valid infix expression\n");
                scanf("%s", infix);
                infix_prefix(infix, prefix);
                printf("The prefix expression \n");
                printf("%s\n", prefix);
            }