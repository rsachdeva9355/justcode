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

long arr[100001];
pair< pair<long, long>, long> processed[100001];
pair< pair<long, long>, long> preprocess[100001];

long max(long a, long b) {
	return a > b ? a : b;
}

int main() {
	long n, m;
	cin >> n >> m;
	long arr[n + 1];
    long prevNum = -1;
    long count = 0;
    long prevIndex = -1;
	for (long i = 1; i <= n; i++) {
		cin >> arr[i];
        if (prevNum != arr[i]) {
            if (i != 1) {
                preprocess[count++] = (make_pair(make_pair(prevIndex, i), prevNum));
            }
            prevNum = arr[i];
            prevIndex = i;
        }
        if (i == n) {
            preprocess[count++] = (make_pair(make_pair(prevIndex, i + 1), prevNum));
        }
	}
    for (long i = 0; i < count; i++) {
        pair< pair<long, long>, long > p = preprocess[i];
        // cout << p.first.first << " "  << p.first.second << " " << p.second << endl;
        for (long j = p.first.first; j < p.first.second; j++) {
            processed[j] = p;
        }
    }
	while(m--) {
		long l, r, k;
		cin >> l >> r >> k;
		long midIndex = l + (r - l + 1)/2;
        pair< pair<long, long>, long > p = processed[midIndex];
        long myl, myr;
        myl = max(p.first.first, l);
        myr = min(p.first.second, r + 1);
        if (myr - myl >= k) {
            cout << p.second << endl;
        } else {
            cout << -1 << endl;
        }
	}
	return 0;
}