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

bool visited[1000];
int height[1000];
int even = 0;

long findDepth(int **graph, int n, int s) {
    visited[s] = 1;
    long myDepth = 0;
    for (int i = 1; i <= n; i++) {
        // cout << s << ":" << i << endl;
        int d;
        if (graph[s][i] > 0 && !visited[i]) {
            d = findDepth(graph, n, i) + 1;
            if (d > 0 && d % 2 == 0) {
                even++;
            } else {
                myDepth += findDepth(graph, n, i) + 1;
            }
        }
    }
    height[s] = myDepth;
    return myDepth;
}

void solve(int **graph, int n) {
    findDepth(graph, n, 1);
    long count = 0;
    for (int i = 1; i <= n; i++) {
        if (height[i] > 0 && height[i] % 2 == 0) {
            count++;
        }
    }
    cout << even << endl;
}

int main() {
    long n, m;
    cin >> n >> m;
    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
         graph[i] = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            graph[i][j] = 0;
        }        
    }

    for (long i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1; 
    }
    solve(graph, n);
    return 0;
}