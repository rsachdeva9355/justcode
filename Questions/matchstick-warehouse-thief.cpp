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

bool pairCompare(pair<ll, ll> firstElem, pair<ll, ll> secondElem) {
  return firstElem.first > secondElem.first;
}

int main() {
	ll n, c;
	cin >> n >> c;
	ll totalCount = 0;
	vector< pair< ll, ll> > config;
	for (ll i = 0; i < c; i++) {
		ll b, m;
		cin >> b >> m;
		config.push_back(pair<ll, ll>(m, b));
	}

	sort(config.begin(), config.end(), pairCompare);
	for (vector< pair<ll, ll> >::iterator it = config.begin(); it < config.end() && n > 0; it++) {
		if (it -> second > n) {
			totalCount += n * it -> first;
			n = 0;
		} else {
			totalCount += it -> second * it -> first;
			n -= it -> second;
		}
	}
	cout << totalCount << endl;
	return 0;
}