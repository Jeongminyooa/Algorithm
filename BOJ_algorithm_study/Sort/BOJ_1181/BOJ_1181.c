#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

#define SIZE 20000
#define LENGTH 50

// �ܾ� ������ �����ϴ� ����ü
typedef struct {
	char string[LENGTH];
	int len;
}word;

//�պ� ������ �̿��Ͽ� ���� Ǯ��
void merge(word* d, int p, int q, int r) {
	int i = p, j = q + 1, t = 0;

	word temp[SIZE];

	while (i <= q && j <= r) {
		if (d[i].len < d[j].len) temp[t++] = d[i++];
		else if(d[i].len > d[j].len) temp[t++] = d[j++];
		else {
			//���ڿ��� ���̰� ���� ���
			if (strcmp(d[i].string, d[j].string) < 0)
				temp[t++] = d[i++];
			else
				temp[t++] = d[j++];
		}
	}
	while (i <= q) temp[t++] = d[i++];
	while (j <= r) temp[t++] = d[j++];

	t = 0;
	for (i = p; i <= r; i++) d[i] = temp[t++];
}

void mergeSort(word* d, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(d, p, q);
		mergeSort(d, q + 1, r);
		merge(d, p, q, r);
	}
	return;
}
void printWord(char w[][LENGTH], int size) {
	int i;
	for (i = 0; i < size; i++) {
		//���� �ܾ�� �ߺ��� ��� ������� �ʴ´�.
		
		printf("%s\n", w[i]);
		
	}
}
int main()
{
	int n, i, j;
	word dictionary[SIZE];

	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", dictionary[i].string);
		dictionary[i].len = strlen(dictionary[i].string);
	}
	mergeSort(dictionary, 0, n);

	printWord(dictionary, n);

}