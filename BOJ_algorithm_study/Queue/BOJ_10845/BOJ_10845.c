#include <stdio.h>

#define MAX_SIZE 10001
int queue[MAX_SIZE];
int rear, head;

void init() {
	head = rear = 0;
}

int empty() {
	if (head == rear)
		return 1;
	else
		return 0;
}
//���� x�� ť�� �ִ� ����
void push(int x) {
	queue[rear++] = x;
}

// ���� �� �� ���Ҹ� ����, ���
int pop() {
	if (empty())
		return -1;
	return queue[head++];
}

int size() {
	return rear - head;
}

int front() {
	if (empty()) return -1;
	else return queue[head];
}

int back() {
	if (empty())
		return -1;
	else
		return queue[rear - 1];
}

int main(void) {
    int n;
    char command[10];

    scanf_s("%d", &n); //�־����� ����� ��

    init();

    while (n > 0) {
        n--;

        scanf_s("%s", command, 10);

        if (strcmp(command, "push") == 0) {
            int num;
            scanf_s("%d", &num);
            push(num);
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
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", back());
        }
    }
}