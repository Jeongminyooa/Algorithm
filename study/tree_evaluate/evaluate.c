// 수식 트리
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int evaluate(TreeNode* p)
{
	if (p == NULL) return 0;
	if (p->left == NULL && p->right == NULL) return p->data;
	else {
		int op1 = evaluate(p->left);
		int op2 = evaluate(p->right);
		printf("%d %c %d을 계산합니다.\n", op1, p->data, op2);
		switch (p->data) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
	return 0;
}
// +
// * +
// 1 4 16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* exp = &n7;

int main(void)
{
	printf("수식의 값은 %d입니다. \n", evaluate(exp));
	return 0;
}