#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 50

//maximum size of stack
char stack[MAX];
int top = -1;

//function to push an element into the stack
void push(char item)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

//function to pop an element from the stack
char pop()
{
    char item;
    if(top == -1)
    {
        printf("Stack Underflow \n");
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

//function to check whether the stack is empty or not
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//function to check whether the character is an operator or not
int isOperator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//function to check the precedence of the operator
int precedence(char symbol)
{
    if(symbol == '^')
    {
        return 3;
    }
    else if(symbol == '*' || symbol == '/' || symbol == '%')
    {
        return 2;
    }
    else if(symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char item;
    char x;
    push('(');
    strcat(infix, ")");
    i = 0;
    j = 0;
    item = infix[i];
    while(item != '\0')
    {
        if(item == '(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if(isOperator(item) == 1)
        {
            x = pop();
            while(isOperator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')')
        {
            x = pop();
            while(x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("Invalid infix expression \n");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    if(top > 0)
    {
        printf("Invalid infix expression \n");
        exit(1);
    }
    postfix[j] = '\0';
}

//function to evaluate the postfix expression
int evaluatePostfix(char postfix[])
{
    int i;
    char item;
    int x, y;
    int result;
    for(i = 0; postfix[i] != '\0'; i++)
    {
        item = postfix[i];
        if(isdigit(item))
        {
            push(item - '0');
        }
        else if(isOperator(item) == 1)
        {
            x = pop();
            y = pop();
            switch(item)
            {
                case '^':
                    result = pow(y, x);
                    break;
                case '*':
                    result = y * x;
                    break;
                case '/':
                    result = y / x;
                    break;
                case '+':
                    result = y + x;
                    break;
                case '-':
                    result = y - x;
                    break;
                case '%':
                    result = y % x;
                    break;
            }
            push(result);
        }
    }
    result = pop();
    return result;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int result;
    printf("Enter the infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("The postfix expression is: ");
    puts(postfix);
    result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d \n", result);
    return 0;
}

