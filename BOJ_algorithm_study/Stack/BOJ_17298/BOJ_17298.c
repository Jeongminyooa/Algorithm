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
        //�迭�� ���� �����ص�.
        index[i] = input;

        //������ ����ִٸ� push=> ���� ù �����̱� ������ ��ū���� �𸥴�.
        if (empty(&nge)) {
            push(&nge, i);
        }
        //peek�Ͽ� input�� ��
        else {
            while (1) {
                //���� ��� �ִٸ� push
                if (empty(&nge)) {
                    push(&nge, i);
                    break;
                }
                //�Է°��� ������ ��ܰ����� ũ�ٸ�
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
    //���ÿ� ���� ������ ��ū���� �����Ƿ� -1 ó��
    for (i = n - 1; i >= 0; i--) {
        if (i == peek(&nge)) {
            int visit = pop(&nge);
            index[i] = -1;
        }
    }
    //���
    for(i = 0; i < n; i++)
        printf("%d ", index[i]);
    free(index);
}