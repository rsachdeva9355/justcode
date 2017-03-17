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

long ranges[201];
long arr[300001];
long sums[300001];
long m, n;

long playGame();

int main() {
    long t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        arr[0] = sums[0] = 0;
        for(long i = 1; i <= n; i++) {
            cin >> arr[i];
            sums[i] = sums[i - 1] + arr[i];
        }
        long left = 1, right = n;
        long finalSum = 0;
        for (long i = 1; i <= m; i++) {
            long range;
            cin >> range;
            range--;
            long l, r, maxSum = 0;
            for (long j = left; j + range<= right; j++) {
                long k = j + range;
                // cout << j << " " << k << endl;
                if (j == k) {
                    if (maxSum < arr[j]) {
                        maxSum = arr[j];
                        l = j;
                        r = j;
                    }
                } else {
                    if (maxSum < sums[k] - sums[j - 1]) {
                        maxSum = sums[k] - sums[j - 1];
                        l = j;
                        r = k;
                    }
                }
            }
            // cout << maxSum << " " << l << ":" << r << endl;
            if (i % 2 == 0) {
                finalSum -= maxSum;
            } else {
                finalSum += maxSum;
            }
            left = l + 1;
            right = r - 1;
        }
        cout << finalSum << endl;
    }
    return 0;
}