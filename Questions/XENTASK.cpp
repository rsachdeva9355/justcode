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
        long n;
        cin >> n;
        long x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for (long i = 0; i < n; i++) {
            long t;
            cin >> t;
            if (i % 2 == 0) {
                x2 += t;
            } else {
                x1 += t;
            }
        }

        for (long i = 0; i < n; i++) {
            long t;
            cin >> t;
            if (i % 2 == 0) {
                y2 += t;
            } else {
                y1 += t;
            }
        }

        long a = y1 + x2;
        long b = y2 + x1;

        if (a < b) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }
    return 0;
}