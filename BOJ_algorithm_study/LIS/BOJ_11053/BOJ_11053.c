// LIS 알고리즘 #1 DP (시간복잡도 :O(n^2)
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int arr[MAX_SIZE];
int dp[MAX_SIZE];

int main() {
	int n, i, j;
	int max = 0;

	scanf_s("%d", &n); // 수열의 크기

	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (i = 0; i < n; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
	}

	for (i = 0; i < n; i++) {
		if (max < dp[i])
			max = dp[i];
	}

	printf("%d\n", max);
}