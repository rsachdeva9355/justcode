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

#define ll long long

map< long, vector<long> > primeFactors;

void prefill() {
	primeFactors.insert(make_pair(2, vector<long>{11}));
	primeFactors.insert(make_pair(3, vector<long>{3, 37}));
	primeFactors.insert(make_pair(4, vector<long>{11, 101}));
	primeFactors.insert(make_pair(5, vector<long>{41, 271}));
	primeFactors.insert(make_pair(6, vector<long>{3,7,11,13,37}));
	primeFactors.insert(make_pair(7, vector<long>{239,4649}));
	primeFactors.insert(make_pair(8, vector<long>{11,73,101,137}));
	primeFactors.insert(make_pair(9, vector<long>{3,3,37,333667}));
	primeFactors.insert(make_pair(10, vector<long>{11,41,271,9091}));
}

long moduloPower(long x, long y, long p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll moduloMultiply(ll a, ll b, ll m){
    ll result = 0;
    a %= m;
    b %= m;
    while (b)
    {
        if (b % 2 != 0)
        {
            result = (result + a) % m;
        }
        a = (a * 2) % m;
        b /= 2;
    }
    return result;
}

long modOfReverse(long n, long mod) {
	return (moduloPower(n, mod - 2, mod) % mod);
}

long findNumberOfDigits(long a) {
	long count = 0;
	while(a) {
		count ++;
		a/=10;
	}
	return count;
}

long findModOfOnes(ll nod, long mod) {
	if (nod == 1) {
		return 1;
	}
	vector<long> factors = primeFactors.find(nod) -> second;
	long result = 1;
	for (long i = 0; i < factors.size(); i++) {
		result = moduloMultiply(result, modOfReverse(factors[i], mod), mod) % mod;
	}
	return result;
}

void solve(long a, ll n, long m, long nod) {
	map<long, long> powerMap;
	long numerator = moduloMultiply(a%m, ((moduloPower(10, n * nod +  1, m)) - 1) % m, m);
	long three = moduloPower(3, m - 2, m);
	long denominator = findModOfOnes(nod, m);
	cout << numerator << " " << three << " " << denominator << endl;
	cout << moduloMultiply(numerator, moduloMultiply(three, moduloMultiply(three, denominator, m), m), m) % m << endl;
}

int main() {
	prefill();
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		long a, m;
		cin >> a >> n >> m;
		long noOfDigits = findNumberOfDigits(a);
		solve(a, n, m, noOfDigits);
	}
	return 0;
}