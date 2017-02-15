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

bool findSum(long arr[], long begin, long end, long sum) {
	if (begin > end) {
		return false;
	}
	if (begin == end) {
		return arr[begin] == sum;
	}
	return findSum(arr, begin + 1, end, sum) || findSum(arr, begin + 1, end, sum - arr[begi\ 1`_P0'/O Zhttp://mynt.to/ahc649655wjLn]);
}

int main() {
	long t;
	cin >> t;
	long arr[t + 1];
	long sum = 0;
	for (long i = 0; i < t; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % 2 != 0) {
		cout << "false" << endl;
	} else {
		string answer = findSum(arr, 0, t - 1, sum/2) ? "true" : "false";
		cout << answer << endl;
	}
	return 0;
}