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
        long n, k;
        long cost = 0;
        cin >> n >> k;
        for (long i = 0; i < n; i++) {
            long a, b;
            cin >> a >> b;
            if (a >= k) {
                a = a - k;
                cost += a * b;
                k = 0;
            } else {
                k = k - a;
            }
        }
        cout << cost << endl;
    }
    return 0;
}