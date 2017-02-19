#include <iostream>
#include <cstring>
#include <vector>

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
    bool visited[n + 1];
    long answer = 0;
    memset(rank, 1, n);

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (long i = 0; i < n; i++) {
        arr[i] = i;
        rank[i] = 1;
        nodes[i] = 1;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        doUnion(arr, rank, nodes, x,y);
    }

    vector<int> sizes;
    for (int i = 0; i < n; i++) {
        int p = find(arr, i);
        if (!visited[p]) {
            visited[p] = 1;
            sizes.push_back(nodes[p]);
        }
    }
    for (int i = 0; i < sizes.size(); i++) {
        for (int j = i + 1; j < sizes.size(); j++) {
            answer += sizes[i] * sizes[j];
        }
    }
    cout << answer << endl;
    return 0;
}