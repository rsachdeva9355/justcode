#include<iostream>
#include<cstring>

using namespace std;

int find(int *arr, int n) {
	if (arr[n] != n) {
		return find(arr, arr[n]);
	}
	return n;
}

void doUnion(int *arr, int *rank, int x, int y) {
	if (arr[x] != arr[y]) {
		if (rank[arr[x]] >= rank[arr[y]]) {
			rank[arr[x]] += rank[arr[y]];
			arr[y] = arr[x];
		} else {
			rank[arr[y]] += rank[arr[x]];
			arr[x] = arr[y];
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int arr[n + 1];
	int rank[n + 1];
	memset(rank, 1, n);

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		doUnion(arr, rank, x,y);
	}

	for (int i = 1; i <= n; i++) {
		cout << find(arr, i) << endl;
	}

	return 0;
}