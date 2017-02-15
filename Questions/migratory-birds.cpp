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

	long arr[6];

	int main() {
		long t;
		cin >> t;
		for (long i = 0; i < t; i++) {
			long a;
			cin >> a;
			arr[a]++;
		}
		long maxNum = -1;
		long max = 0;
		for (int i = 1; i <6; i++) {
			if (arr[i] > arr[max]) {
				max = i;
			}
		}
		cout << max << endl;

		return 0;
	}