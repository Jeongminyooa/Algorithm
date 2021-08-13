//BOJ_7576 ½Ç¹ö1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}element;

#define MAX 1001
#define MAX_QUEUE 1000050

int dist[MAX][MAX];
int tomato[MAX][MAX];
element queue[MAX_QUEUE];
int front = 0, rear = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int n, int m)
{
	int r, c;
	element e;
	int max = -10;

	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			if (tomato[r][c] == 0)
				dist[r][c] = -1;
			if (tomato[r][c] == 1) {
				e.x = r;
				e.y = c;
				queue[rear++] = e;
			}
		}
	}
	while (front < rear) {
		element pop = queue[front++];

		for (int i = 0; i < 4; i++) {
			int nx = pop.x + dx[i];
			int ny = pop.y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (tomato[nx][ny] == 0 && dist[nx][ny] < 0) {
					e.x = nx;
					e.y = ny;
					dist[nx][ny] = dist[pop.x][pop.y] + 1;
					queue[rear++] = e;
				}
			}
		}
	}
	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			if (dist[r][c] == -1) {
				printf("-1\n");
				return;
			}
			if (max <= dist[r][c])
				max = dist[r][c];
		}
	}
	printf("%d\n", max);

}
int main()
{
	int n, m;
	int r, c;

	scanf_s("%d %d", &m, &n);

	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			scanf_s("%d", &tomato[r][c]);
		}
	}
	BFS(n, m);
}