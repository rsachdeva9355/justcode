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

int findIndex(long i, long k, long n) {
    long res = i + k;
    if (res > n - 1) {
        res = res - n;
    }
    return res;
}

int main(){
    long n;
    long k;
    long q;
    cin >> n >> k >> q;
    vector<int> a(n);
    cout << 'a' - 96;
    for(long a_i = 0;a_i < n;a_i++){
       cin >> a[findIndex(a_i, k, n)];
    }
    for(long a0 = 0; a0 < q; a0++){
        long m;
        cin >> m;
        cout << a[m] << endl;
    }
    return 0;
}