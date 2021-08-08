// ���� �˻� Ʈ��
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//Ž�� : ��ȯ
TreeNode* search_recursion(TreeNode* root, int key)
{
	if (root == NULL)
		return NULL;
	
	if (key == root->data)
		return root;
	else {
		if (key < root->data)
			return search(root->left, key);
		else
			return search(root->right, key);
	}
}

//Ž�� : �ݺ�
TreeNode* search_loop(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->data)
			return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

//����
TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = key;
		temp->left = temp->right = NULL;
		return temp;
	}
	else {
		if (node->data < key)
			node->left = insert_node(node->left, key);
		else
			node->right = insert_node(node->right, key);
	}
	return node;
}

//����
TreeNode* delete_node(TreeNode* node, int key)
{
	if (node == NULL) return node;

	if (key < node->data)
		node->left = delete_node(node->left, key);
	else if (key > node->data)
		node->right = delete_node(node->right, key);
	else {
		if (node->left == NULL) {
			TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			TreeNode* temp = node->left;
			free(node);
			return temp;
		}
		else {
			TreeNode* temp = min_value_node(node->right);
			node->data = temp->data;
			node->right = delete_node(node->right, node->data);
		}
	}
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}
int main()
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
	return 0;
}