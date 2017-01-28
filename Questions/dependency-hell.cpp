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

vector<int> graph[1000001];
int indegree[1000001];

int main() {
	
	long q;
	cin >> q;

	while (q--) {
		long n, m;
		cin >> n >> m;
        priority_queue<long, vector<long>, greater<long>> pq;
		for (long i = 1; i <= n; i++) {
			long dependencies;
			cin >> dependencies;
			for (long j = 0; j < dependencies; j++) {
				long index;
				cin >> index;
				graph[index].push_back(i);
                indegree[i] ++;
			}
		}
        for (long i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                pq.push(i);
            }
        }
        int j = 1;
        long topological[n + 1];
        long before[n + 1];
        while(!pq.empty()) {
            long next = pq.top();
            before[next] = j;
            topological[j++] = next;
            pq.pop();
            int sz = (long)graph[next].size();
            for (long i = 0; i < sz; i++)
            {
                long node = graph[next][i];
                indegree[node]--;
                if (indegree[node] == 0)
                    pq.push(node);
            }
        }
        long maxInstallation = -1;
        for (long i = 0; i < m; i++) {
            long a;
            cin >> a;
            if (before[a] > maxInstallation) {
                maxInstallation = before[a];
            }
        }
        cout << maxInstallation << endl;

        for (long i = 1; i <= maxInstallation; i++) {
            cout << topological[i] << " ";
        }
        cout << endl;

	}
	return 0;
}