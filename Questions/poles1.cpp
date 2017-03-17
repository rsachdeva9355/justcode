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

map<pair<long long, long long>, long long> minCostCache;
map<pair<long long, long long>, long long> costCache;

long long getCost(vector<long long> &h, vector<long long> &w, long long l, long long r) {
    if (costCache.find(make_pair(l, r))  == costCache.end()) {
        long long cost = 0;
        for (long long i = l; i <= r; i++) {
            cost += w[i] * (h[i] - h[l]);
        }
        costCache[make_pair(l, r)] = cost;
    }
    return costCache[make_pair(l, r)];
}


long long findCost(vector<long long> &h, vector<long long> &w, long long l, long long r, long long k) {
    if (minCostCache.find(make_pair(l, k)) == minCostCache.end()) {
        long long N = r - l + 1;
        if (k > N) return LONG_MAX;
        if (k == 1) {
            return getCost(h, w, l, r);
        }
        long long cost = LONG_MAX;
        for (long long i = 0; i <= N - k; i++) {
            long long rCost = findCost(h, w, l + i + 1, r, k - 1);
            long long currentCost = getCost(h, w, l, l + i);
            cost = min(cost, rCost + currentCost);
        }
        minCostCache[make_pair(l, k)] = cost;
    }
    return minCostCache[make_pair(l, k)];
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> h(n), w(n);
    for (long long i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }
    cout << findCost(h, w, 0, n - 1, k) << endl; 
    return 0;
}