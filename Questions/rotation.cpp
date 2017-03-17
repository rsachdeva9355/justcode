#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long getIndex(long n, long k, long a) {
    long ind = a - k;
    if (ind < 0) {
        ind = n + ind;
    }
    return ind;
}

int main() {
    long n, k, q;
    cin >> n >> k >> q;
    if (k >= n) {
        k = k % n;
    }
    vector<long> arr(n);
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long i = 0; i < q; i++) {
        long a;
        cin >> a;
        cout << getIndex(n, k, a)<<endl;
    }
    return 0;
}
