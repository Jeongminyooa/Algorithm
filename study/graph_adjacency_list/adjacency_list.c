//그래프 표현 #2 인접 리스트 (무방향 그래프)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef int element;
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

// 간선 삽입 연산(무방향), v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
	//각 리스트에 연결될 노드
	GraphNode* nodeV, * nodeU;
	
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	nodeU = (GraphNode*)malloc(sizeof(GraphNode));
	nodeU->vertex = v;
	nodeU->link = g->adj_list[u];
	g->adj_list[u] = nodeU;

	nodeV = (GraphNode*)malloc(sizeof(GraphNode));
	nodeV->vertex = v;
	nodeV->link = g->adj_list[v];
	g->adj_list[v] = nodeV;
}

// 간선 삭제 연산
void remove_node(GraphNode** phead, element item) { 
    GraphNode* p, * prevp;

    if (*phead == NULL)
        printf("리스트는 비어있습니다.\n");
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
            printf("%d은 리스트에 없음\n", item);
    }
}
// 간선 삭제 연산, v를 u의 인접 리스트에서 삭제한다.
void delete_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }

    // 코드 삽입
    // (u, v)를 삭제한다. remove_node를 사용.
    remove_node(&g->adj_list[u], v);
    remove_node(&g->adj_list[v], u);
}