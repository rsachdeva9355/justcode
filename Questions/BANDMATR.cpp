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

int abso(int a) {
    return a < 0 ? -a : a;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count[n + 1];
        for (int i = 0; i < n; i++)
            count[i] = 0;
        int zeroCount = 0;
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                count[abso(i - j)]++;      
                if (a == 0) {
                    zeroCount++;
                } else {
                    oneCount++;
                }
            }
        }
        if (oneCount == n || oneCount == 0) {
            cout << 0 << endl;
            continue;
        }
        int bandwidth = n - 1;
        for (int i = n - 1; i > 0; i--) {
            int val = count[i];
            if (zeroCount > val) {
                zeroCount -= val;
                bandwidth--;
            } else {
                break;
            }
        }
        cout << bandwidth << endl;
    }
    return 0;
}