#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 501

typedef struct {
	int x, y;
}element;

element queue[MAX_SIZE * MAX_SIZE];
int front = 0, rear = 0;
int vis[MAX_SIZE][MAX_SIZE];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

typedef struct {
	int n, m;
	int mat[MAX_SIZE][MAX_SIZE];
}Picture;

void init(Picture* p)
{
	int r, c;

	for (r = 0; r < p->n; r++) 
		for (c = 0; c < p->m; c++) 
			p->mat[r][c] = 0;
}

void BFS(Picture* p) {
	int r, c;
	int width = 0;
	int max = -1000;
	int count = 0;
	element e;

	for (r = 0; r < p->n; r++) {
		for (c = 0; c < p->m; c++) {
			if (p->mat[r][c] == 1 && !vis[r][c]) {
				width = 0; // 새로운 그림을 조사하기 위해서 초기화
				vis[r][c] = 1; //방문함
				e.x = r;
				e.y = c;
				queue[rear] = e; //푸쉬
				rear++;
				width++;
				count++;
				while (front < rear) {
					element pop = queue[front++];

					//상하좌우 그림인지 확인함
					for (int i = 0; i < 4; i++) {
						int nx = pop.x + dx[i];
						int ny = pop.y + dy[i];

						if (nx >= 0 && nx < p->n && ny >= 0 && ny < p->m && p->mat[nx][ny] == 1 && !vis[nx][ny]) {
							e.x = nx;
							e.y = ny;
							queue[rear] = e;
							rear++;
							vis[nx][ny] = 1;
							width++;
						}
					}
				}
				if (max <= width)
					max = width;
			}
		}
	}
	if (count == 0)
		printf("0\n0\n");
	else
		printf("%d\n%d\n", count, max);
	return;
}

int main()
{
	int n, m;
	int r, c;
	Picture* picture = (Picture*)malloc(sizeof(Picture));

	scanf_s("%d %d", &picture->n, &picture->m);

	init(picture);

	for (r = 0; r < picture->n; r++) {
		for (c = 0; c < picture->m; c++) {
			scanf_s("%d", &picture->mat[r][c]);
		}
	}
	BFS(picture);
}
