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


long abs(long a) {
    return a < 0 ? -a : a;
}

int main() {
    long t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        string str;
        cin >> str;
        vector<int> ones;
        for (long i = 0; i < n; i++) {
            long a;
            a = str[i] - '0';
            if (a == 1) {
                ones.push_back(i);
            }
        }
        if (ones.size() == n) {
            cout << 0 << endl;
            continue;
        }
        long result = INT_MAX;
        for (long i = 0; i < ones.size(); i++) {
            long myDiff = 0;
            for (long j = 0; j < ones.size(); j++) {
                cout << i << ":" << j << " ";
                long diff1 = abs(ones[j] - ones[i]);
                long diff2 = n - diff1;
                cout << diff1 << " " << diff2 << endl;
                myDiff += min(diff1, diff2);
            }
            if (myDiff < result) {
                result = myDiff;
            }
        }
        cout << result << endl;
    }
    return 0;
}