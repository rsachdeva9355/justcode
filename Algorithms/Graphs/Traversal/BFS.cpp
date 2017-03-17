#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int graph[100][100];

bool visited[1000];

void bfs(int i, int n) {
    if (visited[i]) {
        return;
    }
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = 1;
        cout << node << " visited" << endl;
        for (int j = 0; j < n; j++) {
            if (graph[node][j] == 1 && !visited[j]) {
                q.push(j);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
       bfs(i, n);
    }
    return 0;
}