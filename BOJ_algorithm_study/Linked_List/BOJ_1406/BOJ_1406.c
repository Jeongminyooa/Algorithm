#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 100000

//노드는 알파벳 한 글자와 이전, 다음 알파벳을 가리키는 주솟값으로 구성
typedef struct {
	char alpha;
	TextEditor* llink;
	TextEditor* rlink;
}TextEditor;

//커서
typedef struct {
	TextEditor* cursor;
}CursorType;

void init(TextEditor* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// pre는 커서
void insert_left(TextEditor* pre, char c)
{
	TextEditor* newnode = (TextEditor*)malloc(sizeof(TextEditor));
	newnode->alpha = c;
	newnode->rlink = pre;
	newnode->llink = pre->llink;
	pre->llink->rlink = newnode;
	pre->llink = newnode;
}
int main() {
	char text[MAX_CHAR];
	int len, i;

	TextEditor* head = (TextEditor*)malloc(sizeof(TextEditor));
	CursorType* cursor = NULL;

	init(head);

	scanf_s("%s", text, MAX_CHAR);

	len = strlen(text);
	for (i = 0; i < len; i++) {
		insert(i, editor);
	}
}