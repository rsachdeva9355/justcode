// http://www.geeksforgeeks.org/find-number-of-islands/

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

// int graph[5][5];

bool visited[1000];

void dfs(int graph[5][5], int i, int n) {
    if (visited[i]) {
        return;
    }
    visited[i] = 1;
    cout << i << " entered" << endl;
    for (int j = 0; j < n; j++) {
        if (graph[i][j] != 0 && !visited[j]) {
            dfs(graph, j, n);
        }
    }
    cout << i << " exited" << endl;
}

int countIslands(int graph[5][5], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            count++;
        }
        dfs(graph, i, n);
    }
    return count;
}

int main() {
    int graph[5][5] =
    {   {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIslands(graph, 5));
    return 0;
}   