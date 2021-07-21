#include <stdio.h>

#define MAX_SIZE 100001

typedef struct {
	int deque[MAX_SIZE];
	int head, tail;
}dequeType;

void init(dequeType* d) {
	d->head = d->tail = MAX_SIZE / 2;
}

void push_front(dequeType* d, int data) {
	if (d->head < 0) printf("front full\n");
	else d->deque[--d->head] = data;
}

void push_back(dequeType* d, int data) {
	if (d->tail >= MAX_SIZE) printf("back full\n");
	else d->deque[d->tail++] = data;
}

int pop_front(dequeType* d) {
	if (empty(d)) return -1;
	else return d->deque[d->head++];
}

int pop_back(dequeType* d) {
	if (empty(d)) return -1;
	else return d->deque[--(d->tail)];
}

int size(dequeType* d) {
	return d->tail - d->head;
}

int empty(dequeType* d) {
	if (d->head == d->tail) return 1;
	else return 0;
}

int front(dequeType* d) {
	if (empty(d)) return -1;
	else return d->deque[d->head];
}

int back(dequeType* d) {
	if (empty(d)) return -1;
	else return d->deque[d->tail - 1];
}

int main()
{
    int n;
    char command[100];
    dequeType d;

    scanf_s("%d", &n); //주어지는 명령의 수

    init(&d);

    while (n > 0) {
        n--;

        scanf_s("%s", command, 100);

        if (strcmp(command, "push_front") == 0) {
            int num;
            scanf_s("%d", &num);
            push_front(&d, num);
        }
        else if (strcmp(command, "push_back") == 0) {
            int num;
            scanf_s("%d", &num);
            push_back(&d, num);
        }
        else if (strcmp(command, "pop_front") == 0) {
            printf("%d\n", pop_front(&d));
        }
        else if (strcmp(command, "pop_back") == 0) {
            printf("%d\n", pop_back(&d));
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&d));
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty(&d));
        }
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", front(&d));
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", back(&d));
        }
    }
}
