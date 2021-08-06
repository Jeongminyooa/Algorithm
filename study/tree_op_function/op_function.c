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
TreeNode m7 = { 28, NULL, NULL }; // �߰� 
TreeNode m4 = { 25, NULL, &m7 }; // ���� 
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

TreeNode* root3 = &n6;

//�ܸ� ��� ���� ���
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
// ��ܸ� ��� ���� ���
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

//�ڽ��� �ϳ��� ��ܸ� ����� ����
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

//�ڽ��� �ΰ��� ��ܸ� ����� ����
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

//��尪 �� �ִ밪�� ��ȯ
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

//��尪 �� �ּڰ��� ��ȯ
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

//Ʈ������ key���� ã�� result�� �ּҰ��� ����. ������ ��ȯ
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

//���� Ʈ���� ������ ���� 1�� ����
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
		printf("%d ", root->data); // ��� �湮
		preorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		preorder(root->right); // �����ʼ���Ʈ�� ��ȸ
	}
}

// �� ���� ���� Ʈ���� ���� ������ ���� �ְ� ���� �����͸� ���� �ִ��� �˻�
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

// �־��� ���� Ʈ���� ������ ���ο� Ʈ���� ��ȯ
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
	printf("root Ʈ���� ���� ���\n");

	printf("�ܸ� ��� ���� : %d\n", get_leaf_count(root)); //3
	printf("��ܸ� ��� ���� : %d\n", get_noleaf_count(root)); // 3
	printf("�ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root)); //1
	printf("�ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root)); //2
	printf("�ִ밪�� ���� ����� ���� %d\n", get_max(root)); //25
	printf("�ּҰ��� ���� ����� ���� %d\n", get_min(root)); //4
	printf("15�� ���� = %d\n", search(root, 15));
	preorder(root);
	node_increase(root);
	preorder(root); // 1�� �����Ͽ����� Ȯ��

	printf("\n-------------------------------------------\n");
	printf("root2 Ʈ���� ���� ���\n");

	printf("�ܸ� ��� ���� : %d\n", get_leaf_count(root2)); //3
	printf("��ܸ� ��� ���� : %d\n", get_noleaf_count(root2)); // 4
	printf("�ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));//2
	printf("�ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2)); //2
	printf("�ִ밪�� ���� ����� ���� %d\n", get_max(root2)); //28
	printf("�ּҰ��� ���� ����� ���� %d\n", get_min(root2)); //4

	printf("\n-------------------------------------------\n");
	printf("root�� root2�� ������? [ %d ]\n", equal(root, root2));
	printf("root�� root3�� ������? [ %d ]\n", equal(root, root3));

	printf("root2�� ������ �� 1�� ���� root4\n");
	TreeNode* root4 = copy(root2);
	node_increase(root4);
	preorder(root4);
	printf("\n\n������ root2\n");
	preorder(root2);
}