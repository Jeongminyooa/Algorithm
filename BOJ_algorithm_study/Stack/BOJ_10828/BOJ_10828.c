#include <stdio.h>
#define SIZE 10000
int arr[SIZE];
int top = 0;

int push(int x)
{
    if (top >= SIZE) return 0;
    arr[top++] = x;
    return 1;
}

int pop()
{
    if (top <= 0) return -1;
    else return arr[--top];
}

int size() {
    return top;
}

int empty() {
    if (top == 0) return 1;
    else return 0;
}

int get_top() {
    if (top >= SIZE || top <= 0)
        return -1;

    return arr[top - 1];
}

int main(void) {
    int n;
    char command[10];

    scanf_s("%d", &n); //주어지는 명령의 수

    while (n > 0) {
        n--;

        scanf_s("%s", command, 10);

        if (strcmp(command, "push") == 0) {
            int num;
            scanf_s("%d", &num);
            int rlt = push(num);

            if (rlt == -1)
                printf("error\n");
        }
        else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(command, "top") == 0) {
            printf("%d\n", get_top());
        }
    }
}