#include <stdio.h>
#define SIZE 1000001

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
    int* index;
    stackType nge;

    init(&nge);

    scanf_s("%d", &n); 

    index = (int*)malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++) {
        int input;
        scanf_s("%d", &input);
        //배열에 값을 저장해둠.
        index[i] = input;

        //스택이 비어있다면 push=> 가장 첫 원소이기 때문에 오큰수를 모른다.
        if (empty(&nge)) {
            push(&nge, i);
        }
        //peek하여 input과 비교
        else {
            while (1) {
                //만약 비어 있다면 push
                if (empty(&nge)) {
                    push(&nge, i);
                    break;
                }
                //입력값이 스택의 상단값보다 크다면
                if (index[peek(&nge)] < input) {
                    index[peek(&nge)] = input;
                    int visit = pop(&nge);
                }
                else {
                    push(&nge, i);
                    break;
                }
            }
        }
    }
    //스택에 남는 수들은 오큰수가 없으므로 -1 처리
    for (i = n - 1; i >= 0; i--) {
        if (i == peek(&nge)) {
            int visit = pop(&nge);
            index[i] = -1;
        }
    }
    //출력
    for(i = 0; i < n; i++)
        printf("%d ", index[i]);
    free(index);
}