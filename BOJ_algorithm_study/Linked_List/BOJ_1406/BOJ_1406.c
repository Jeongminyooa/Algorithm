#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 100000

//노드는 알파벳 한 글자와 이전, 다음 알파벳을 가리키는 주솟값으로 구성
typedef struct TextEditor {
	char alpha;
	struct TextEditor* llink;
	struct TextEditor* rlink;
}TextEditor;

//커서
typedef struct {
	struct TextEditor* link;
}CursorType;

void init(TextEditor* head, TextEditor* tail) 
{
	head->llink = tail;
	head->rlink = tail;
	tail->llink = head;
	tail->rlink = head;
}

// pre의 왼쪽에 삽입한다.
void insert_left(TextEditor* pre, char c)
{
	TextEditor* newnode = (TextEditor*)malloc(sizeof(TextEditor));
	newnode->alpha = c;

	newnode->rlink = pre;
	newnode->llink = pre->llink;
	pre->llink->rlink = newnode;
	pre->llink = newnode;
}

//removed 노드(커서가 가리키는 것의 llink) 삭제
void delete (TextEditor* head, CursorType* c) {
	TextEditor* removed = c->link->llink;

	if (removed == head) return;
	else {
		removed->llink->rlink = removed->rlink;
		removed->rlink->llink = removed->llink;
		free(removed);
	}
}

void Dshift(CursorType* c, TextEditor* head) {
	if (c->link->rlink == head) return;
	c->link = c->link->rlink;
}

void Lshift(CursorType* c, TextEditor* head) {
	if (c->link->llink == head) return;
	c->link = c->link->llink;
}

void printText(TextEditor* head, TextEditor* tail) {
	TextEditor* node;
	for (node = head->rlink; node != tail; node = node->rlink) {
		printf("%c", node->alpha);
	}
	printf("\n");
	return;
}
char inputCommand() {
	char command;
	scanf_s("%c", &command);
	return command;
}
int main() {
	char text[MAX_CHAR];
	int len, i, n;

	TextEditor* head = (TextEditor*)malloc(sizeof(TextEditor));
	TextEditor* tail = (TextEditor*)malloc(sizeof(TextEditor));

	//초기 커서는 문장의 맨 끝에 위치
	CursorType* cursor = (CursorType*)malloc(sizeof(CursorType));
	cursor->link = tail;

	init(head, tail);

	scanf_s("%s", text, MAX_CHAR);
	getchar();

	len = strlen(text);
	for (i = 0; i < len; i++) {
		insert_left(tail, text[i]);
	}

	scanf_s("%d", &n);
	while (n > 0) {
		n--;
		getchar();
		switch (inputCommand()) {
		case 'L':
			Lshift(cursor, head);
			break;
		case 'D':
			Dshift(cursor, head);
			break;
		case 'B':
			delete(head, cursor);
			break;
		case 'P': {
			getchar();
			char ch;
			scanf_s("%c", &ch);
			insert_left(cursor->link, ch);
			break;
		}
		}
	}
	printText(head, tail);
}