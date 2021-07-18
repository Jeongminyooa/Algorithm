#include <stdio.h>
#include <stdlib.h>

//합병 정렬을 이용하여 문제 풀이
void merge(int A[], int p, int q, int r) {
	int i = p, j = q + 1, t = 0;
	int* temp = (int*)malloc(sizeof(int) * (r - p + 1));

	while (i <= q && j <= r) {
		if (A[i] < A[j]) temp[t++] = A[i++];
		else temp[t++] = A[j++];
	}
	while (i <= q) temp[t++] = A[i++];
	while (j <= r) temp[t++] = A[j++];

	t = 0;
	for (i = p; i <= r; i++) A[i] = temp[t++];

	free(temp);

}

void mergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
	return;
}
void printSort(int A[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d\n", A[i]);
}
void inputSort(int A[], int size) {
	int i;
	for (i = 0; i < size; i++)
		scanf_s("%d", &A[i]);
}
int main()
{
	int n;
	int* arr;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	inputSort(arr, n);
	mergeSort(arr, 0, n - 1);
	printSort(arr, n);

	free(arr);
	return 0;
}