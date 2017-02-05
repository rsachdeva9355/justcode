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

ll modulo(ll a, ll b, ll m){
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

long findModuloPower10(long power, long mod, map<long, long> &powerMap) {
	if (powerMap.find(power) != powerMap.end()) {
		return powerMap[power];
	}
	if (power < 6) {
		long answer = pow((long)10,(long)power) % (long	)mod;
		powerMap.insert(make_pair(power, answer));
		return answer;
	}
	long result = modulo(findModuloPower10(power/2, mod, powerMap), findModuloPower10(power - power/2, mod, powerMap), mod);
	powerMap.insert(make_pair(power, result));
	//cout << "result " << result << endl;
	return result;
}

ll solve(long a, ll n, long m, long nod) {
	map<long, long> powerMap;
	map<long, long> repititionMap, reverseMap;
	ll result = 0;
	ll am = a % m;
	ll prevModulo = am;
	repititionMap.insert(make_pair(prevModulo, 0));
	reverseMap.insert(make_pair(0, prevModulo));
	for (ll i = 1; i < n; i++) {
		prevModulo = ((prevModulo % m) + modulo(am, findModuloPower10(i * nod, m, powerMap), m)) % m;
		if (repititionMap.find(prevModulo) == repititionMap.end()) {
			repititionMap.insert(make_pair(prevModulo, i));
			reverseMap.insert(make_pair(i, prevModulo));
		} else {
			ll repitionStartIndex = repititionMap.find(prevModulo) -> second;
			ll totalReps = i - repitionStartIndex;
			if (totalReps == 1) {
				return prevModulo;
			}
			return (reverseMap.find(n % (totalReps + 1)) -> second);
		}
	}
	return prevModulo;
}

long findNumberOfDigits(long a) {
	long count = 0;
	while(a) {
		count ++;
		a/=10;
	}
	return count;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		long a, m;
		cin >> a >> n >> m;
		long noOfDigits = findNumberOfDigits(a); 
		cout << solve(a, n, m, noOfDigits) << endl;
	}
	return 0;
}