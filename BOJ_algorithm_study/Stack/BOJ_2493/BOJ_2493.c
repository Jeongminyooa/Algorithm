#include <stdio.h>
#define SIZE 500000

typedef struct {
    int* stack;
    int top;
}stackType;
void init(stackType* s) {
    s->stack = (int*)malloc(sizeof(int) * SIZE);
    s->top = 0;
}
int push(stackType* s, int x)
{
    if (s->top >= SIZE) return 0;
    s->stack[s->top++] = x;
    return 1;
}
int pop(stackType* s)
{
    if (s->top <= 0) return -1;
    else return s->stack[--s->top];
}
int empty(stackType* s) {
    if (s->top == 0) return 1;
    else return 0;
}
int peek(stackType* s) {
    if (s->top >= SIZE || s->top <= 0)
        return -1;

    return s->stack[s->top - 1];
}
int main(void) {
    int n, i;
    int* input;
    stackType tower;

    init(&tower);

    scanf_s("%d", &n); //탑의 수

    input = (int*)malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++) {
        int t;
        scanf_s("%d", &t);
        input[i] = t;
        
        //스택이 비어있다면 push한 후 0 출력 => 가장 첫 원소이기 때문이다.
        if (empty(&tower)) {
            push(&tower, i);
            printf("0 ");
        }
        //peek한 탑 높이와 input과 비교
        else {
            while (1) {
                if (empty(&tower)) {
                    push(&tower, i);
                    printf("0 ");
                    break;
                }
                if (input[peek(&tower)] < t) {
                    int visit = pop(&tower);
                }
                else {
                    printf("%d ", peek(&tower) + 1);
                    push(&tower, i);
                    break;
                }
            }
        }
    }
    free(input);
}