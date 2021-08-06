//���Ḯ��Ʈ�� �̿��� ť
#include <stdio.h> 
#include <malloc.h> 

typedef int element; // ����� Ÿ�� 

typedef struct QueueNode { // ť�� ����� Ÿ�� 
	element item;
	struct QueueNode* link;
} QueueNode;

typedef struct { // ť ADT ���� 
	QueueNode* front, * rear;
} LinkedQueueType;

void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q)
{
	return q->rear == NULL;
}

//���Ḯ��Ʈ���� ��ȭ ���´� ����!
int is_full(LinkedQueueType* q)
{
	return 0;
}

void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->item = item;
	node->link = NULL;

	if (is_empty(q)) {
		q->front = q->rear = node;
	}
	else {
		q->rear->link = node;
		q->rear = node;
	}
}

element dequeue(LinkedQueueType* q)
{
	QueueNode* remove = q->front;
	element item;

	if (is_empty(q)) {
		printf("ť�� ��� ����\n");
		exit(1);
	}
	else {
		item = remove->item;
		q->front = remove->link;
		free(remove);
		return item;
	}
}

// ����� ť �׽�Ʈ �Լ� 
void main()
{
	LinkedQueueType q;
	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
}