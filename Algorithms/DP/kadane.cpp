// (Dynamic Programming) Algorithm used to find the maximum sum of a sub array in an array

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

int kadane(int arr[], int size) {
	int maxSoFar = 0;
	int maxOverall = INT_MIN;
	for (int i = 0; i < size; i++) {
		maxSoFar += arr[i];
		if (maxSoFar < 0) {
			maxSoFar = 0;
		} else {
			maxOverall = max(maxOverall, maxSoFar);
		}
	}
	return maxOverall;
}

int main() {
	int arr[5] = {3, 2, 3, 4, 5};
	cout << kadane(arr, 5);
	return 0;
}