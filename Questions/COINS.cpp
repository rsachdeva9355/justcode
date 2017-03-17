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

map<long, long long> sums;

long long maxSum(long long n) {
    if (n <= 2) {
        return n;
    }
    if (sums.find(n) != sums.end()) {
        return sums.find(n)->second;
    }
    long long s = max(n, maxSum(n/2) + maxSum(n/3) + maxSum(n/4));
    sums.insert(make_pair(n, s));
    return s;
}

int main() {
    long long num;
    while(cin >> num) {
        cout << maxSum(num) << endl;
    }
    return 0;
}