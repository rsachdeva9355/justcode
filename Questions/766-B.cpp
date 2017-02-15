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
	long n;
	cin >> n;
	long arr[n + 1];
	for (long i = 0;i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (long i = 0; i < n - 2; i++) {
		long k = i + 2;
        for (long j = i+1; j < n; j++)
        {
            while (k < n && arr[i] + arr[j] <= arr[k]) {
               k++;
            }
            if (k != n) {
            	cout << "YES" << endl;
            	return 0;
            }
        }
	}
	cout << "NO" << endl;
	return 0;
}