// LIS 알고리즘 #2 binary search (시간복잡도 :O(nlogn))
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000001

int lis[MAX_SIZE];
int arr[MAX_SIZE];
int temp[MAX_SIZE]; // 수열 LIS 자리를 저장함.
int rlt[MAX_SIZE];

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
	int t;
	int lis_idx = 0;

	scanf_s("%d", &n); // 수열의 크기

	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);

		if (i == 0) {
			lis[lis_idx] = arr[i];
			temp[i] = lis_idx;
		}

		if (arr[i] > lis[lis_idx]) {
			lis[++lis_idx] = arr[i];
			temp[i] = lis_idx;
		}
		else {
			int index = lower_bound(0, lis_idx, arr[i]);
			lis[index] = arr[i];
			temp[i] = index;
		}
	}
	//LIS 길이 출력
	printf("%d\n", lis_idx + 1);

	t = n - 1;
	i = 0;
	// temp에 저장된 번호를 역순으로 trace
	while (lis_idx >= 0) {
		if (temp[t] == lis_idx) {
			rlt[i++] = arr[t];
			lis_idx--;
		}
		t--;
	}

	for (t = i - 1; t >= 0; t--)
		printf("%d ", rlt[t]);
}