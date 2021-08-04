#include <stdio.h>

#define MAX 500001

typedef struct {
	int prev, next;
}Node;

Node list[MAX];
int lis[MAX];
int temp[MAX]; //각 원소의 LIS 길이를 저장하는 배열
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

	//0(head)부터 N개까지의 이중 연결 리스트 생성
	for (i = 0; i <= N; i++) {
		list[i].next = i + 1;

		if (i == 0) continue;
		list[i].prev = i - 1;
	}

	// 연산에 따라 이중 연결 리스트를 재생성
	for (i = 0; i < M; i++) {
		scanf_s(" %c", &op, 1);
		scanf_s("%d %d", &a, &b);

		//a의 prev와 next를 끊어줌.
		list[list[a].next].prev = list[a].prev;
		list[list[a].prev].next = list[a].next;

		//a와 b를 서로 연결함.
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

		//b와 관련되었던 노드를 a와 연결함
		list[list[a].prev].next = a;
		list[list[a].next].prev = a;
	}
	
	/*LIS를 이용해 최소 연산 횟수를 구함
	LIS를 제외한 나머지 수를 정렬하면 된다.*/
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
		reverse = i; // 마지막 원소를 저장
	}
	 longest = lis_idx;

	//최소 연산 횟수 출력
	 if(N != 0)
		printf("%d\n", N - (lis_idx + 1));

	//LIS의 끝 원소까지는 A 연산
	t = N - 1;

	// temp에 저장된 번호를 역순으로 trace -> 원소를 찾아서 rlt에 저장
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