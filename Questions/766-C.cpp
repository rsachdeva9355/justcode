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

int allowed[27];

bool isValidPrefix(string str, int l, int r) {
	for (int i = l; i <= r; i++) {
		int a = str[i] - 96;
		if (allowed[a] < (r - l + 1)) {
			return 0;
		}
	}
	return 1;
}

long solve(string str, long l) {
	long count = 0;
	if (l == str.length() - 1) {
		return 1;
	}
	for (long i = l; i < str.length() - 1; i++) {
		for (long j = i; j <= str.length(); j++) {
			if (isValidPrefix(str, i, j)) {
				cout << str.substr(i, j + 1) << endl;
				count += solve(str, j+1);
			} else {
				break;
			}
		}
	}
	return count;
}

int main() {
	int len;
	cin >> len;

	string str;
	cin >> str;

	for (int i = 1; i <= 26; i++) {
		cin >> allowed[i];
	}
	cout << solve(str, 0);
	return 0;
}