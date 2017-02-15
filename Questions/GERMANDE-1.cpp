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

int main() {
	long t;
	cin >> t;
	while(t--) {
		bool success = false;
		long o1, o2;
		cin >> o1 >> o2;
		long n = o1 * o2;
		long arr[n + 1];
		long sums[o1 + 1];
		long currentSum = 0;
		long ind = 0;
		long favOneSum = 0;
		long bestOfO1 = o1/2;
		long bestOfO2 = o2/2;
		for (long i = 0, dist = 0; i < n; i++) {
			cin >> arr[i];
			currentSum += arr[i];
			ind++;
			if (ind == o2) {
				sums[dist++] = currentSum;
				if (currentSum > bestOfO2) {
					favOneSum++;
				}
				currentSum = 0;
				ind = 0;
			}
		}
		if (favOneSum > bestOfO1) {
			cout << 1 << endl;
			success = true;
			continue;
		}
		for (long i = 0; i < o2; i++) {
			for(long j = 0; j < o1; j++) {
				long a = (j * o2) + i;
				long b = a + o2 >= n ? a + o2 - n : a + o2;
				if (sums[j] > bestOfO2) {
					favOneSum--;
				}
				sums[j] -= arr[a];
				sums[j] += arr[b];
				if (sums[j] > bestOfO2) {
					favOneSum++;
				}
			}
			if (favOneSum > bestOfO1) {
				cout << 1 << endl;
				success = true;
				break;
			}
		}
		if (!success) {
			cout << 0 << endl;
		}
	}
	return 0;
}