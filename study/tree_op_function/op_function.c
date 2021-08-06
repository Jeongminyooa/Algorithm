#include <stdio.h>
#include <stdlib.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
}TreeNode;
/*
root	 15
	4			15
15			16		25
*/
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

/*
root2	 15
	4			15
15			16		25
						28
*/
TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // 추가 
TreeNode m4 = { 25, NULL, &m7 }; // 변경 
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

TreeNode* root3 = &n6;

//단말 노드 개수 계산
int get_leaf_count(TreeNode* t)
{
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			return 1;
		else {
			return get_leaf_count(t->left) + get_leaf_count(t->right);
		}
	}
	return 0;
}
// 비단말 노드 개수 계산
int get_noleaf_count(TreeNode* t)
{
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			return 0;
		else {
			return 1 + get_noleaf_count(t->left) + get_noleaf_count(t->right);
		}
	}
	return 0;
}

//자식이 하나인 비단말 노드의 개수
int get_oneleaf_count(TreeNode* t) {
	if (t != NULL) {
		if (t->left != NULL && t->right == NULL)
			return 1 + get_oneleaf_count(t->left);
		else if (t->left == NULL && t->right != NULL)
			return 1 + get_oneleaf_count(t->right);
		else {
			return get_oneleaf_count(t->left) + get_oneleaf_count(t->right);
		}
	}
	return 0;
}

//자식이 두개인 비단말 노드의 개수
int get_twoleaf_count(TreeNode* t) {
	if (t != NULL) {
		if (t->left != NULL && t->right != NULL)
			return 1 + get_twoleaf_count(t->left) + get_twoleaf_count(t->right);
		else {
			return get_twoleaf_count(t->left) + get_twoleaf_count(t->right);
		}
	}
	return 0;
}

//노드값 중 최대값을 반환
int get_max(TreeNode* t)
{
	int max = 0;

	if (t != NULL) {
		int lt = get_max(t->left);
		int rt = get_max(t->right);

		max = MAX(lt, rt);
		max = MAX(t->data, max);
	}
	return max;
}

//노드값 중 최솟값을 반환
int get_min(TreeNode* t)
{
	int min = 100;

	if (t != NULL) {
		int lt = get_min(t->left);
		int rt = get_min(t->right);

		min = MIN(lt, rt);
		min = MIN(t->data, min);
	}
	return min;
}

//트리에서 key값을 찾아 result에 주소값을 저장. 개수를 반환
int search(TreeNode* t, int key)
{
	if (t != NULL) {
		if (t->data == key) {
			return 1 + search(t->left, key) + search(t->right, key);
		}
		else 
			return search(t->left, key) + search(t->right, key);
	}
	return 0;
}

//이진 트리의 노드들의 값을 1씩 증가
void node_increase(TreeNode* t)
{
	if (t != NULL) {
		t->data++;
		node_increase(t->left);
		node_increase(t->right);
	}
	return;
}
void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); // 노드 방문
		preorder(root->left); // 왼쪽서브트리 순회
		preorder(root->right); // 오른쪽서브트리 순회
	}
}

// 두 개의 이진 트리가 같은 구조를 갖고 있고 같은 데이터를 갖고 있는지 검사
int equal(TreeNode* r1, TreeNode* r2)
{
	if (r1 == NULL && r2 == NULL)
		return 1;
	if (r1 != NULL && r2 != NULL) {
		if (r1->data != r2->data) return 0;
		else {
			int le = equal(r1->left, r2->left);
			int re = equal(r1->right, r2->right);

			if (le == re) return 1;
		}
	}
	return 0;
}

// 주어진 이진 트리를 복제한 새로운 트리를 반환
TreeNode* copy(TreeNode* t)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	if (t != NULL) {
		temp->data = t->data;
		temp->left = copy(t->left);
		temp->right = copy(t->right);
		return temp;
	}
	return NULL;
}
int main()
{
	printf("root 트리의 연산 결과\n");

	printf("단말 노드 개수 : %d\n", get_leaf_count(root)); //3
	printf("비단말 노드 개수 : %d\n", get_noleaf_count(root)); // 3
	printf("자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root)); //1
	printf("자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root)); //2
	printf("최대값을 갖는 노드의 값은 %d\n", get_max(root)); //25
	printf("최소값을 갖는 노드의 값은 %d\n", get_min(root)); //4
	printf("15의 개수 = %d\n", search(root, 15));
	preorder(root);
	node_increase(root);
	preorder(root); // 1씩 증가하였는지 확인

	printf("\n-------------------------------------------\n");
	printf("root2 트리의 연산 결과\n");

	printf("단말 노드 개수 : %d\n", get_leaf_count(root2)); //3
	printf("비단말 노드 개수 : %d\n", get_noleaf_count(root2)); // 4
	printf("자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));//2
	printf("자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2)); //2
	printf("최대값을 갖는 노드의 값은 %d\n", get_max(root2)); //28
	printf("최소값을 갖는 노드의 값은 %d\n", get_min(root2)); //4

	printf("\n-------------------------------------------\n");
	printf("root와 root2는 같은가? [ %d ]\n", equal(root, root2));
	printf("root와 root3는 같은가? [ %d ]\n", equal(root, root3));

	printf("root2를 복제한 후 1씩 더한 root4\n");
	TreeNode* root4 = copy(root2);
	node_increase(root4);
	preorder(root4);
	printf("\n\n원래의 root2\n");
	preorder(root2);
}