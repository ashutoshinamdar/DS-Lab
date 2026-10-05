#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = c;
}

char pop(void)
{
    if(top == -1)
    {
        return '\0';
    }
    return stack[top--];

}

char peek(void)
{
    if(top == -1)
    {
        return '\0';
    }
    return stack[top];
}

int isEmpty(void)
{
    return top == -1;
}

int isOperand(char c)
{
    return isalnum(c);
}

int precedence(char op)
{
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

void intopos(char infix[],char postfix[])
{
    int i,j=0;
    char ch;

    for(i=0;infix[i]!='\0';i++)
    {
        ch = infix[i];
        if(isOperand(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(!isEmpty() && peek()!='(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else if(ch == '*' || ch == '+' || ch == '/' || ch == '-')
        {
            while(!isEmpty() && peek() != '(' && precedence(peek()) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
    }
    while(!isEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter an valid infix exp");
    scanf("%s",infix);
    top = -1;
    intopos(infix,postfix);
    printf("Infix exp:%s",infix);
    printf("Postfix exp:%s\n",postfix);
}
