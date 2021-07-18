//Counting Sort를 사용해서 문제 해결 10989
#include <stdio.h>

#define SIZE 10001
int cnt[SIZE];

int main()
{
	int n;
	int idx; // count에 쓰일 인덱스
	long long i;
	int j;

	scanf_s("%d", &n);

	//n의 범위가 0 <= N <= 10,000,000이므로 long long 사용
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