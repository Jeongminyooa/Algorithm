#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* left, * right;
}TreeNode;

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	else return;
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
	else return;
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
	else return;
}

// ��Ʈ ������ �����Ͽ� target�� ��带 ã��(������ȸ)
TreeNode* searchNode(TreeNode* root, char target) {
	if (root != NULL) {
		if (root->data == target) {
			return root;
		}
		TreeNode* tmp = searchNode(root->left, target);
		if (tmp != NULL)
			return tmp;

		return searchNode(root->right, target);
	}
	return NULL;
}

// parent ����� ����, ������ �ڽ� ��带 ����
void linkChild(TreeNode* parent, char ch1, char ch2)
{
	TreeNode* n1, * n2;

	if (ch1 == '.')	n1 = NULL;
	else {
		n1 = (TreeNode*)malloc(sizeof(TreeNode));
		n1->data = ch1;
		n1->left = NULL;
		n1->right = NULL;
	}

	if (ch2 == '.') n2 = NULL;
	else {
		n2 = (TreeNode*)malloc(sizeof(TreeNode));
		n2->data = ch2;
		n2->left = NULL;
		n2->right = NULL;
	}

	parent->left = n1;
	parent->right = n2;

	return;
}

int main()
{
	int n, i;
	char par, ch1, ch2;

	scanf_s("%d", &n); //����� ���� �Է�

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 'A';
	root->left = NULL;
	root->right = NULL;

	i = n;
	while (i > 0) {
		scanf_s(" %c %c %c", &par, 1, &ch1, 1, &ch2, 1);
		getchar();

		TreeNode* p;
		
		if (i == n) p = root; //ù �Է��̶��
		else p = searchNode(root, par); //��带 ã�Ƽ� ����

		linkChild(p, ch1, ch2);

		i--;
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);

	return 0;
}