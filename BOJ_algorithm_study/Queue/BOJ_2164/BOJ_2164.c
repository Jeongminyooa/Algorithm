#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int* queue;
	int rear, head;
	int size;
}circleQueue;

void init(circleQueue* q, int n) {
	q->queue = (int*)malloc(sizeof(int) * n);
	q->size = n;
	q->rear = q->head = 0;
}

void enqueue(circleQueue* q, int x) {
	q->rear = (q->rear + 1) % q->size;
	q->queue[q->rear] = x;
}

int dequeue(circleQueue* q) {
	q->head = (q->head + 1) % q->size;
	return q->queue[q->head];
}

void removeHead(circleQueue* q) {
	q->head = (q->head + 1) % q->size;
}

int empty(circleQueue* q) {
	if (q->rear == q->head)
		return 1;
	else return 0;
}

int full(circleQueue* q) {
	if ((q->rear + 1) % q->size == q->head)
		return 1;
	else return 0;
}

int isOne(circleQueue* q) {
	if ((q->head + 1) % q->size == q->rear)
		return 1;
	else return 0;
}

int main()
{
	int n, i;
	circleQueue queue;

	scanf_s("%d", &n);

	init(&queue, n + 1); // ť �ʱ�ȭ

	// 1 ~ n ������ ���ڸ� ����ť�� �־��ش�.
	for (i = 0; i < n; i++) {
		enqueue(&queue, i + 1);
	}

	// ����ť�� ���ڰ� 1�� ���������� �ݺ��Ѵ�.
	while (!isOne(&queue)) {
		removeHead(&queue);
		int replace = dequeue(&queue);
		enqueue(&queue, replace);
	}

	printf("%d\n", dequeue(&queue));
	return 0;
}