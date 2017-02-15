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

vector< pair<ll, ll> > ranges;

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first < b.first;
}

bool areOverlapping(pair<ll,ll> a, pair<ll,ll> b) {
	if (a.second >= b.first) {
		return true;
	}
	return false;
}

int main() {
	long n;
	ll L, R;
	cin >> n >> L >> R;
	ll arr[n + 1];
	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (long i = n - 1; i >= 1; i--) {
		ll left = arr[i] - arr[i-1] + 1;
		ll right = arr[i] + arr[i-1] - 1;
		if ((left > R && right > R) || (left < L && R < L)) {
			continue;
		}
		pair<ll,ll> range = make_pair(left, right);
		ranges.push_back(range);
	}
	if (ranges.size() == 0) {
		cout << 0 << endl;
	} else {
		sort(ranges.begin(), ranges.end(), compare);
		ll count = 0;
		vector< pair<ll,ll> > newRanges;
		newRanges.push_back(ranges[0]);
		ll j = 0;
		for (ll i = 1; i < ranges.size(); i++) {
			if (areOverlapping(newRanges[j], ranges[i])) {
				newRanges[j] = make_pair(min(ranges[i].first, newRanges[j].first), max(ranges[i].second, newRanges[j].second));
			} else {
				j++;
				newRanges.push_back(ranges[i]);
			}
		}
		for (ll i = 0; i < newRanges.size(); i++) {
			// cout << newRanges[i].first << "->" << newRanges[i].second << endl;
			// if (L == R && newRanges[i].second > R && newRanges[i].first < L) {
			// 	count++;
			// }
			count += min(newRanges[i].second, R) - max(newRanges[i].first, L) + 1;
		}
		cout << count << endl;
	}
	return 0;
}