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
	long long a, b;
	cin >> a >> b;
	long long n;
	cin >> n;

	stack<pair<long long, long long> > directions;

	for (long long i = 0;i < n; i++) {
		long long x, y;
		cin >> x >> y;
		directions.push(pair<long long, long long>(x, y));
	}

	for (long long i = 0;i < n; i++) {
		pair<long, long> direction = directions.top();
		directions.pop();
		a -= direction.first;
		b -= direction.second;
	}

	cout << a << " " << b << endl;

	return 0;
}