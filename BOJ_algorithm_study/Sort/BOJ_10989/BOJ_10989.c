//Counting Sort�� ����ؼ� ���� �ذ� 10989
#include <stdio.h>

#define SIZE 10001
int cnt[SIZE];

int main()
{
	int n;
	int idx; // count�� ���� �ε���
	long long i;
	int j;

	scanf_s("%d", &n);

	//n�� ������ 0 <= N <= 10,000,000�̹Ƿ� long long ���
	for (i = 0; i < n; i++) {
		scanf_s("%d", &idx);
		cnt[idx]++;
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
		}
	}

}