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

bool score[10000001];

int main() {
	string str;
	cin >> str;
	pair<int, int> charCount = pair<int, int> (0, 0);
	for (long i = 0; i < str.length(); i++) {
		long value = charCount.first * charCount.second;
		score[value] = 1;
		if ((str[i] - 96) == charCount.first) {
			charCount.second = charCount.second + 1;
		} else {
			charCount = pair<int, int>(str[i] - 96, 1);
		}
			
	}
	long value = charCount.first * charCount.second;
	score[value] = 1;

	long t;
	cin >> t;
	while(t--) {
		int query;
		cin >> query;
		if (score[query] == 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}