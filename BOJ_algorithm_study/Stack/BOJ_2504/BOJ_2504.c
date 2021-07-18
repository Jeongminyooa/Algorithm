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
    else return 0;
}
int main(void) {
    char input[SIZE];
    int rlt = 0;
    int temp = 1; // 중간 더하기 값
    int error = 0;

    gets(input);

    init();
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            temp *= 2;
            push(input[i]);
        }
        else if (input[i] == '[') {
            temp *= 3;
            push(input[i]);
        }
        else if (input[i] == ')') {
            //쌍이 맞지 않는다면 error 발생시켜 break -> 실행시간 단축
            if (peek() != '(' || empty()) {
                error = 1;
                break;
            }
            if (input[i - 1] == '(')
                rlt += temp;

            pop();

            temp /= 2;
        }
        else if (input[i] == ']') {
            if (peek() != '[' || empty()) {
                error = 1;
                break;
            }

            if (input[i - 1] == '[')
                rlt += temp;

            pop();

            temp /= 3;
        }
    }
    if (empty() && !error) printf("%d\n", rlt);
    else printf("0\n");

    return 0;
}