#include <stdio.h>
#define SIZE 10000
int arr[SIZE];
int top = 0;

int push(int x)
{
    if (top >= SIZE) return -1;
    arr[top++] = x;
    return 0;
}

int pop()
{
    if (top <= 0) return -1;
    else return arr[top--];
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

    return arr[top];
}

int main(void) {
    int n;
    char command;

    scanf("%d", &n); //주어지는 명령의 수

    
}