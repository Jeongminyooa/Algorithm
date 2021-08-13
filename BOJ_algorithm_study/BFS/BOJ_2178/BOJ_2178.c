// BOJ_2178 �ǹ�1
#include <stdio.h>
#include <stdlib.h>

#define MAX 101

typedef struct {
	int x, y;
	int min_cnt; // �ּ� ĭ ���� ���� ���� ����
}element;

int matrix[MAX][MAX];
int vis[MAX][MAX];
element queue[MAX * MAX];
int front = 0, rear = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int n, int m) {
	int r, c;
	element e;

	vis[0][0] = 1; // ���� ��ġ�� �湮�ߴٰ� ǥ����
	e.x = 0;
	e.y = 0;
	e.min_cnt = 1;
	queue[rear++] = e; // ť�� Ǫ����

	while (front < rear) {
		element pop = queue[front++];

		for (int i = 0; i < 4; i++) {
			int nx = pop.x + dx[i];
			int ny = pop.y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m ) {
				if (matrix[nx][ny] == 1 && !vis[nx][ny]) {
					e.x = nx;
					e.y = ny;
					e.min_cnt = pop.min_cnt + 1;
					queue[rear] = e;
					rear++;
					vis[nx][ny] = 1;

					if (nx == n - 1 && ny == m - 1) {
						// ���� ��ġ��� �� Ž������ �ʰ� ������.
						front = rear;
						break;
					}
				}
			}
		}
	}
	printf("%d", e.min_cnt);
	return;
}

int main()
{
	char input;
	int n, m;
	int r, c;

	scanf_s("%d %d", &n, &m);

	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			scanf_s("%1d", &matrix[r][c]);
		}
	}

	BFS(n, m);
}