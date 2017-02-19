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

#define MOD 1000000007

long visited[1000000];

long power10[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

long multiply(long a, long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long add(long a, long b) {
    return (a % MOD + b % MOD) % MOD;       
}

int main() {
    string str;
    cin >> str;
    long len = str.length();
    long long int res = 0;
    long long int f = 1;
    for(int i = len-1; i >= 0; i--) {
        res = (res + (str[i]-'0')*f*(i+1)) % MOD;
        f = (f*10+1) % MOD;
    }
    cout << res << endl;
    return 0;
}