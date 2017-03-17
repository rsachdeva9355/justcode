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

long long maxNum = 100000;
bool prime[100001];
vector<long long> primes;

void doit() {
    for (long long i = 0; i < maxNum; i++) {
        prime[i] = 1;
    }
}

void seive()
{
    for (long long p=2; p*p <= maxNum; p++)
    {
        if (prime[p] == true)
        {
            for (long long i = p*2; i <= maxNum; i += p) {
                prime[i] = false;
            }
        }
    }
    primes.push_back(2);
    for (long long i = 3; i <= maxNum; i+=2) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}

bool isPrime(long long n) {
    if (n < 2) {
        return false;
    }
    for (long long i = 0; i < primes.size(); i++) {
        if (primes[i] >= n * n) {
            break;
        }
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    doit();
    seive();
    long long t;
    cin >> t;
    while(t--) {
        long long l, r;
        cin >> l >> r;
        for (long long i = l; i <= r; i++) {
            if (isPrime(i)) {
                cout << i << endl;
            }
        }
        if (t >= 1) {
            cout << endl;
        }
    }
    return 0;
}