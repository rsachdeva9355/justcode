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
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << -1 << endl;	
	} else {
		long length = a.length() > b.length() ? a.length() : b.length();
		cout << length << endl;
	}
	return 0;
}