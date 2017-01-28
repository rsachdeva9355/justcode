#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

long long find(long long *arr, long long n) {
	if (arr[n] != n) {
		return find(arr, arr[n]);
	}
	return n;
}

void doUnion(long long *arr, long long *rank, long long *nodes, long long x, long long y) {
	long long px = find(arr, x);
	long long py = find(arr, y);
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
	long long t;
	cin >> t;
	while (t--) {
		long long n, m;
		cin >> n >> m;
		long long arr[n + 1];
		long long rank[n + 1];
		long long nodes[n + 1];
		long long faltu[n + 1];

		for (long long i = 1; i <= n; i++) {
			arr[i] = i;
			rank[i] = 1;
			nodes[i] = 1;
			faltu[i] = 0;
		}
		for (long long i = 0; i < m; i++) {
			long long x,y;
			cin >> x >> y;
			if (find(arr, x) != find(arr, y)) {
				doUnion(arr, rank, nodes, x, y);
			} else {
				faltu[find(arr, x)]++;	
			}
		}
		long long parentSizes[n + 1];
		long long j = 0;
		for (long long i = 1; i <= n; i++) {
			if (find(arr, i) == i) {
				parentSizes[j++] = nodes[i];
			}
		}
		sort(parentSizes, parentSizes + j, greater<long long>());
		long long prev_max = 0;
		long long curr_max = 0;
		for (long long i = 0; i < j; i++) {
			curr_max += ((parentSizes[i] - 1) * (parentSizes[i]) * (parentSizes[i] + 1)) / 3L + (prev_max * (parentSizes[i] - 1));
			prev_max += parentSizes[i] * (parentSizes[i] - 1);
		}
		cout << curr_max << endl;
	}
	return 0;
}