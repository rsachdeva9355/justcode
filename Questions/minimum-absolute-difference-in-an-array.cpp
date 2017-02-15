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

long myabs(long a) {
	return a < 0 ? -a : a;
}


int main() {
	long t;
	cin >> t;
	vector<long> arr(t);
	for (long i = 0; i < t; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long minDiff = INT_MAX;
	for (long i = 0; i < t - 1; i++) {
		long diff = arr[i + 1] - arr[i];
		long as = myabs(diff);
		if (as < minDiff) {
			minDiff = as;
		}
	}

	cout << minDiff << endl;
	return 0;
}