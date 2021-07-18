#include <stdio.h>
#include <string.h>
#define SIZE 100
char arr[SIZE];
int top = -1;

void init() {
    top = -1;
}

int push(char x)
{
    if (top >= SIZE - 1) return -1;
    return arr[++top] = x;

}

int pop()
{
    if (top < 0) return -1;
    else return arr[top--] = '\0';
}

char peek() {
    if (top >= SIZE - 1 || top < 0)
        return -1;

    return arr[top];
}
int empty() {
    if (top == -1) return 1;
    else return -1;
}
int main(void) {
    char input[SIZE];

    gets(input);

    while (strcmp(input, ".") != 0) {
        init();

        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '(' || input[i] == ')' || input[i] == '[' || input[i] == ']') {
                if (peek() == '(' && input[i] == ')') pop();
                else if (peek() == '[' && input[i] == ']') pop();
                else
                    push(input[i]);
            }
        }
        if (empty() == 1)
            printf("yes\n");
        else
            printf("no\n");

        gets(input);
    }
    return 0;
}