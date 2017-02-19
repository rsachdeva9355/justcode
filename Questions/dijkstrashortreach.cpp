#include<iostream>
#include<queue>
#include<climits>
#include<vector>

using namespace std;

typedef bool (*comp)(pair<int,int>, pair<int,int>);
bool compare(pair<int, int> a, pair<int, int> b)
{
   return (a.second < b.second);
}

void djikstra(int **graph, int n, int source) {
    
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n, m;
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

    for (int i = 0; i < m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (graph[x][y] != 0) {
            w = min(w, graph[x][y]);
        }
        graph[x][y] = w;
        graph[y][x] = w; 
    }
    int source;
    cin >> source;
    priority_queue< pair<int, int>, vector< pair<int, int> >, comp> pq(compare);
    
    int distance[n + 1];
    
    memset(distance, INT_MAX, sizeof(distance) * (n + 1));
    distance[source] = 0;

    pq.push(pair<int, int>(source, distance[source]));

    while (!pq.empty()) {
        int curr = pq.top().first;
        pq.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (graph[curr][i] > 0) {
                if (distance[curr] + graph[curr][i] < distance[i]) {
                    distance[i] = distance[curr] + graph[curr][i];
                    pq.push(pair<int, int>(i, distance[i]));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != source) {
            if (distance[i] == INT_MAX) {
                cout << -1 << " ";
            } else {
                cout << distance[i] << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}