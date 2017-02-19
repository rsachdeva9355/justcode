#include<iostream>
#include<cstring>

using namespace std;

int find(long *arr, long n) {
	if (arr[n] != n) {
		return find(arr, arr[n]);
	}
	return n;
}

void doUnion(long *arr, long *rank, long *nodes, long x, long y) {
	long px = find(arr, x);
	long py = find(arr, y);
	if (rank[px] > rank[py]) {
		nodes[px] += nodes[py];
		arr[py] = px;
	} else {
		nodes[py] += nodes[px];
		arr[px] = py;
	}
	if (rank[px] == rank[py]) {
		rank[py] += 1;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	long arr[n + 1];
	long rank[n + 1];
	long nodes[n + 1];
	memset(rank, 1, n);

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		doUnion(arr, rank, nodes, x,y);
	}

	return 0;
}