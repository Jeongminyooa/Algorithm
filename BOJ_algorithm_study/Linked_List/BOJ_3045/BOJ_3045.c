#include <stdio.h>

#define MAX 500001

typedef struct {
	int prev, next;
}Node;

Node list[MAX];
int lis[MAX];
int temp[MAX]; //�� ������ LIS ���̸� �����ϴ� �迭
int rlt[MAX];

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
	int N, M, a, b;
	int i, t = 0, lis_idx = 0;
	int longest, reverse;
	char op;

	scanf_s("%d %d", &N, &M);

	//0(head)���� N�������� ���� ���� ����Ʈ ����
	for (i = 0; i <= N; i++) {
		list[i].next = i + 1;

		if (i == 0) continue;
		list[i].prev = i - 1;
	}

	// ���꿡 ���� ���� ���� ����Ʈ�� �����
	for (i = 0; i < M; i++) {
		scanf_s(" %c", &op, 1);
		scanf_s("%d %d", &a, &b);

		//a�� prev�� next�� ������.
		list[list[a].next].prev = list[a].prev;
		list[list[a].prev].next = list[a].next;

		//a�� b�� ���� ������.
		switch (op) {
		case 'A':
			list[a].prev = list[b].prev;
			list[a].next = b;
			break;
		case 'B':
			list[a].prev = b;
			list[a].next = list[b].next;
			break;
		}

		//b�� ���õǾ��� ��带 a�� ������
		list[list[a].prev].next = a;
		list[list[a].next].prev = a;
	}
	
	/*LIS�� �̿��� �ּ� ���� Ƚ���� ����
	LIS�� ������ ������ ���� �����ϸ� �ȴ�.*/
	for (i = list[0].next; i != N + 1; i = list[i].next) {
		if (i == list[0].next) {
			lis[lis_idx] = i;
			temp[t] = lis_idx;
		}

		if (i > lis[lis_idx]) {
			lis[++lis_idx] = i;
			temp[t++] = lis_idx;
		}
		else {
			int lb = lower_bound(0, lis_idx, i);
			lis[lb] = i;
			temp[t++] = lb;
		}
		reverse = i; // ������ ���Ҹ� ����
	}
	 longest = lis_idx;

	//�ּ� ���� Ƚ�� ���
	 if(N != 0)
		printf("%d\n", N - (lis_idx + 1));

	//LIS�� �� ���ұ����� A ����
	t = N - 1;

	// temp�� ����� ��ȣ�� �������� trace -> ���Ҹ� ã�Ƽ� rlt�� ����
	while (t >= 0) {
		if (temp[t] == lis_idx) {
			rlt[lis_idx--] = reverse;
		}
		reverse = list[reverse].prev;
		t--;
	}

	t = 1;
	for (i = 0; i <= longest; t++) {
		if (rlt[i] == t) {
			i++;
			continue;
		}
		printf("A %d %d\n", t, rlt[i]);
	}

	for (i = lis[longest] + 1; i <= N; i++)
		printf("B %d %d\n", i, i - 1);
	return 0;
}