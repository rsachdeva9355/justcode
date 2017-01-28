#include<iostream>
#include<queue>
#include<vector>

#define MAX_INT 50000

using namespace std;

void print(int **graph, int n) {
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(int **graph, int n) {
    int distance[n + 1][n + 1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            distance[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (distance[j][k] > distance[j][i] + distance[i][k]) {
                    distance[j][k] = distance[j][i] + distance[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (distance[i][j] == MAX_INT) {
                cout << "INF";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
         graph[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = MAX_INT;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
        graph[y][x] = w; 
    }
    floydWarshall(graph, n);
	return 0;
}