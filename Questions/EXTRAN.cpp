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
        vector<long> arr(n);
        for (long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (arr[1] - arr[0] != 1) {
            cout << arr[0] << endl;
        } else if (arr[n - 1] - arr[n - 2] != 1) {
            cout << arr[n-1] << endl;
        } else {
            for (long i = 0; i < n - 1; i++) {
                if (arr[i] == arr[i + 1]) {
                    cout << arr[i] << endl;
                }
            }
        }
    }
    return 0;
}