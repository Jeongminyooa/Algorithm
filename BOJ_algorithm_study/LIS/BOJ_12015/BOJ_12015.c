// LIS 알고리즘 #2 binary search (시간복잡도 :O(nlogn))
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000001

int lis[MAX_SIZE];

int lower_bound(int start, int end, int target) {
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (lis[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}
int main() {
	int n, i, ans;
	int lis_idx = 0;

	scanf_s("%d", &n); // 수열의 크기

	for (i = 0; i < n; i++) {
		scanf_s("%d", &ans);

		if (i == 0) lis[lis_idx] = ans;
		
		if (ans > lis[lis_idx])
			lis[++lis_idx] = ans;
		else
			lis[lower_bound(0, lis_idx, ans)] = ans;
	}
    printf("%d", lis_idx + 1);
}