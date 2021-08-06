//연결리스트를 이용한 스택 코드
#include <stdio.h> 
#include <malloc.h> 

// 스택을 위한 타입 정의 
typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}

//연결리스트에서 꽉 차 있을 때는 없다!
int is_full(LinkedStackType* s)
{
	return 0;
}

void push(LinkedStackType* s, element data)
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->item = data;
	node->link = s->top;
	s->top = node;
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* remove = s->top;
		element t = remove->item;
		s->top = remove->link;
		free(remove);

		return t;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

// 주 함수 
void main()
{
	LinkedStackType s;
	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}