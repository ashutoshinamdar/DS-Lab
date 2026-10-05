#include<stdio.h>
#define max 100

int stack[max];
int top=-1;

void push(int val);
int pop();
void display();

int main()
{
    int choice,val;
  while(1)
    {
    printf("---Menu---\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.display\n");
    printf("4.Exit\n");
    printf("Enter your choice");
    scanf("%d",&choice);



switch(choice)
{
case 1:

    printf("Enter the value");
    scanf("%d",&val);
    push(val);
        break;

case 2:

        pop();
        break;

case 3:

        display();
        break;

case 4:

        break;



default:

        printf("Invalid Choice");


}
}
}
void push(int val)
{
    if(top==max-1){
        printf("Stack Overflow");
    }
    else
    {
    top++;
    stack[top] = val;

    }
}

int pop(void)
        {
            int x;
            if(top==-1)
            {
                printf("Stack Underflow");
                return 0;
            }
           x = stack[top];
           top--;
           printf("Popped successfully");

        }

void display(void)
             {
                 if(top==-1)
                 {
                     printf("Stack Underflow");

                 }
                 else
                 {
                 for(int i=top ;i>=0 ;i--)
                 {
                     printf("%d",stack[i]);
                     printf("\n");
                 }
                 }
             }
