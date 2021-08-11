//�׷��� ǥ�� #1 ���� ���
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int v;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ
void init(GraphType* g)
{
	int r, c;
	g->v = 0;

	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

//���� ���� ����
void insert_vertex(GraphType* g, int n)
{
	if ((g->v) + 1 > MAX_VERTICES) {
		printf("�׷���: ������ ���� �ʰ�\n");
		return;
	}
	g->v++;
}

//���� ���� ���� (������ �׷���)
void insert_edge(GraphType* g, int start, int end)
{
	if (start < 0 || start > g->v || end < 0 || end > g->v) {
		printf("�׷��� : ���� ��ȣ ����\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

//���� ���� ���� (���� �׷���)
void insert_edge_directed(GraphType* g, int start, int end)
{
	if (start < 0 || start > g->v || end < 0 || end > g->v) {
		printf("�׷��� : ���� ��ȣ ����\n");
		return;
	}
	g->adj_mat[start][end] = 1;
}

//���� ���� ����
void delete_edge(GraphType* g, int start, int end)
{
	if (start >= g->v || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}

	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}

//������ ����ϴ� �Լ�
int get_degree(GraphType* g, int v)
{
	int i, count = 0;

	for (i = 0; i < g->v; i++)
		if (g->adj_mat[v][i] == 1)
			count++;
	return count;
}

void print_adj_mat(GraphType* g)
{
	int r, c;

	for (r = 0; r <= g->v; r++) {
		for (c = 0; c <= g->v; c++)
			printf("%d ", g->adj_mat[r][c]);
		printf("\n");
	}
}
void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0;i < 4;i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);
	free(g);
}