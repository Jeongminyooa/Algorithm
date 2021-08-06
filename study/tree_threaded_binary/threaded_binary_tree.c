// 스레드 이진 트리 코드
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

//p의 중위후속자를 찾는 함수
TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;

	if (q == NULL || p->is_thread)
		return q;

	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;
	do {
		printf("%c ", q->data);
		q = find_successor(q);
	} while (q);
}
// 7 
// 3 6 
// 1 2 4 5 
// 
TreeNode n1 = { '1', NULL, NULL, 1 }; // 단말 
TreeNode n2 = { '2', NULL, NULL, 1 }; // 단말 
TreeNode n3 = { '3', &n1, &n2, 0 };
TreeNode n4 = { '4', NULL, NULL, 1 }; // 단말 
TreeNode n5 = { '5', NULL, NULL, 0 }; // 단말이지만 중위 순회의 마지막 노드이므로 0으로 
TreeNode n6 = { '6', &n4, &n5, 0 };
TreeNode n7 = { '7', &n3, &n6, 0 };
TreeNode* exp = &n7;

int main()
{
	//단말 노드의 오른쪽 링크에 중위 후속 노드를 연결한다
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
}