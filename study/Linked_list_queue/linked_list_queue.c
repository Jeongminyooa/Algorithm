//연결리스트를 이용한 큐
#include <stdio.h> 
#include <malloc.h> 

typedef int element; // 요소의 타입 

typedef struct QueueNode { // 큐의 노드의 타입 
	element item;
	struct QueueNode* link;
} QueueNode;

typedef struct { // 큐 ADT 구현 
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

//연결리스트에서 포화 상태는 없다!
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
		printf("큐가 비어 있음\n");
		exit(1);
	}
	else {
		item = remove->item;
		q->front = remove->link;
		free(remove);
		return item;
	}
}

// 연결된 큐 테스트 함수 
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