// 이진 검색 트리
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//탐색 : 순환
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

//탐색 : 반복
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

//삽입
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

//삭제
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
	// 맨 왼쪽 단말 노드를 찾으러 내려감
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
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}