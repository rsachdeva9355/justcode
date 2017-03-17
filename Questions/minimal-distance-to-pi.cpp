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

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253

long double ABS(long double a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int main() {

    long double a, b;
    cin >> a >> b;
    if (a < 7 && b > 7) {
        cout << 22 << "/" << "7" << endl;
    } else if(b - a > 7) {
        int distance = (long long)a % 7;
        long d = a + (7 - distance);
        cout << d/7 * 22 << "/" << d << endl; 
    } else {
    long double minDiff = 999999999999999999.0;
    long long minD, minN;
        for (long long i = a; i <= b; i++) {
            for (long long j = 3 * i; j <= 3.5 * i; j++) {
                // cout <<i << " " << j << " " << (long double)j/(long double)i - PI << endl;
                long double diff = ABS((long double)j/(long double)i - PI);
                if (diff < minDiff) {
                    minDiff = diff;
                    minD = i;
                    minN = j;
                }
            }
        }
        cout << minN << "/" << minD << "\n";
    }
    return 0;
}