//�׷��� ǥ�� #2 ���� ����Ʈ (���� �׷���)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g)
{
	int i;
	g->n = 0;

	for (i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
}
// ���� ���� ����(����), v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge_directed(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
// ���� ���� ����
void remove_node(GraphNode** phead, element item) {
    GraphNode* p, * prevp;

    if (*phead == NULL)
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
    else if ((*phead)->vertex == item) {
        p = *phead;
        *phead = (*phead)->link;
        free(p);
    }
    else {
        p = *phead;
        do {
            prevp = p;
            p = p->link;
        } while (p != NULL && p->vertex != item);
        if (p != NULL) {
            prevp->link = p->link;
            free(p);
        }
        else
            printf("%d�� ����Ʈ�� ����\n", item);
    }
}
