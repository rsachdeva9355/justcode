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

long lis(int arr[], long s, long e, long prevMax, int len) {
	if (s == e) {
		if (prevMax < arr[s]) {
			return len + 1;
		} else {
			return len;
		}
	}
	if (arr[s] > prevMax) {
		return max(lis(arr, s + 1, e, arr[s], len + 1), lis(arr, s + 1, e, prevMax, len));
	} else {
		return max(lis(arr, s + 1, e, prevMax, len), lis(arr, s + 1, e, arr[s], 1));
	}
}

long lisDP(int arr[], long n) {
	int dp[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int maxLen = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxLen = max(maxLen, dp[i]);
	}
	return maxLen;
}

int main() {
	long t;
	cin >> t;
	int arr[t];
	for (long i = 0; i < t; i++) {
		cin >> arr[i];
	}
	//cout << lis(arr, 0, t - 1, INT_MIN, 0) << endl; 
	cout << lisDP(arr, t) << endl; 
	return 0;
}