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

int t;

bool isVisited(map< pair<int, int>, bool > &visited, int i, int j) {
	return visited.find(make_pair(i, j)) != visited.end();
}

vector< pair<int, int> > getPossibleIndices(int x, int y, int a, int b, map< pair<int, int>, bool > &visited) {
	vector< pair<int, int> > possibleIndices;
	cout << "Finding " << x << " " << y << endl;
	if (x + a < t && y + b < t && !isVisited(visited, x + a, y + b)) {
		possibleIndices.push_back(make_pair(x+a, y+b));
	}
	if (x + a < t && y - b >= 0 && !isVisited(visited, x + a, y - b)) {
		possibleIndices.push_back(make_pair(x+a, y-b));
	}
	if (x - a >= 0 && y + b < t && !isVisited(visited, x - a, y + b)) {
		possibleIndices.push_back(make_pair(x-a, y+b));
	}
	if (x - a >= 0 && y - b >= 0 && !isVisited(visited, x - a, y - b)) {
		possibleIndices.push_back(make_pair(x-a, y-b));
	}

	if (x + b < t && y + a < t && !isVisited(visited, x + b, y + a)) {
		possibleIndices.push_back(make_pair(x+b, y+a));
	}
	if (x + b < t && y - a >= 0 && !isVisited(visited, x + b, y - a)) {
		possibleIndices.push_back(make_pair(x+b, y-a));
	}
	if (x - b >= 0 && y + a < t && !isVisited(visited, x - b, y + a)) {
		possibleIndices.push_back(make_pair(x-b, y+a));
	}
	if (x - b >= 0 && y - a >= 0 && !isVisited(visited, x - b, y - a)) {
		possibleIndices.push_back(make_pair(x-b, y-a));
	}
	for (int i = 0; i < possibleIndices.size(); i++) {
		cout << possibleIndices[i].first << " " << possibleIndices[i].second << endl;
	}
	cout << endl;
	return possibleIndices;
}

long minHops(int x, int y, int a, int b, map< pair<int, int>, bool > &visited) {
	visited.insert(make_pair(make_pair(x, y), true));
	if(x == t - 1 && y == t - 1) {
		return 0;
	}
	vector< pair<int, int> > possibleIndices = getPossibleIndices(x, y, a, b, visited);
	if (possibleIndices.size() == 0) {
		return INT_MAX;
	}
	long min = INT_MAX;
	//cout << "A & B " << a << " " << b << endl;
	for (int i = 0; i < possibleIndices.size(); i++) {
		pair<int, int> p = possibleIndices[i];
		if (visited.find(p) == visited.end()) {
			long v = minHops(p.first, p.second, a, b, visited);
			//cout << x << " " << y << " " << v << endl;
			if (v < min) {
				min = v; 
			}
		}
	 }
	return min + 1;
}

int main() {
	cin >> t;
	// for (int i = 1; i < t; i++) {
	// 	for (int j = 1; j < t; j++) {
	// 		map< pair<int, int>, bool > visited;
	// 		cout << minHops(0, 0, i, j, visited) << " ";
	// 	}
	// 	cout << endl;
	// }
	map< pair<int, int>, bool > visited;
	cout << minHops(0, 0, 1, 3, visited) << " ";
	return 0;
}