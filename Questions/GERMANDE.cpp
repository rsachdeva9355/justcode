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
	while (t--) {
		bool success = false;
		long o1, o2;
		cin >> o1 >> o2;
		long n = o1 * o2;
		long arr[n + 1];
		long initOnes = 0;
		for (long i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] == 1) {
				initOnes++;
			}
		}
		if ((o1/2 + 1) * (o2/2 + 1) > initOnes) {
			cout << 0 << endl;
			continue;
		}
		if ((o1/2 + 1) * o2 <= initOnes) {
			cout << 1 << endl;
			continue;
		}
		long zeroes = 0, ones = 0;
		for(long i = 0; i < o2; i++) {
			long minister = 0;
			for (long j = i; j < n; j+=o2) {
				for (long k = j; k < j + o2; k++) {
					long temp = k >= n ? k - n : k;
					if (arr[temp] == 0) {
						minister--;
					} else {
						minister++;
					}
				}
				if (minister > 0) {
					ones++;
				} else {
					zeroes++;
				}
				minister = 0;
			}
			// cout << ones << " " << zeroes << endl;
			if (zeroes > (o1/2 + 1)) {
				break;
			}
			if (ones > zeroes) {
				cout << 1 << endl;
				success = true;
				break;
			}
			ones = 0;
			zeroes = 0;
		}
		if (!success) {
			cout << 0 << endl;
		}
	}
	return 0;
}