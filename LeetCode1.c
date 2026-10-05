#include <stdio.h>

#define MAX 100

int main() {
    char s[MAX], stack[MAX];
    int top = -1, valid = 1;

    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack[++top] = s[i];
        else {
            if(top == -1) {
                valid = 0;
                break;
            }

            char x = stack[top--];

            if((s[i] == ')' && x != '(') ||
               (s[i] == '}' && x != '{') ||
               (s[i] == ']' && x != '[')) {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1)
        valid = 0;

    printf(valid ? "Valid" : "Invalid");

    return 0;
}
