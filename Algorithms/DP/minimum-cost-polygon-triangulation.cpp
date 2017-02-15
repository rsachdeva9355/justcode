// http://www.geeksforgeeks.org/minimum-cost-polygon-triangulation/
// http://sarielhp.org/teach/notes/algos/lec/05_dprog_II.pdf

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

#define DOUBLE_MAX 1000000.0

map< pair<int,int>, double > memoize;

double dist(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) +
                (p1.second - p2.second)*(p1.second - p2.second));
}

double cost(vector <pair<int, int> > points, int i, int j, int k) {
	pair<int, int> p1 = points[i], p2 = points[j], p3 = points[k];
    return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

double mTC(vector <pair<int, int> > points, int i, int j) {
	if (j < i + 2) {
		return 0;
	}
	if (memoize.find(make_pair(i, j)) != memoize.end()) {
		cout << "I Found " << i << " " << j << endl;
		return memoize.find(make_pair(i, j)) -> second;
	}
	double minimum = DOUBLE_MAX;
	for (int k = i + 1; k < j; k++) {
		double value = mTC(points, i, k) + mTC(points, k, j) + cost(points, i, k, j);
		minimum = min(minimum, value);
	}
	memoize.insert(make_pair(make_pair(i, j), minimum));
	return minimum;
}

int main() {
	vector<pair<int, int>> points;
	points.push_back(make_pair(0, 0));
 	points.push_back(make_pair(1, 0));
	points.push_back(make_pair(2, 1));
	points.push_back(make_pair(1, 2));
	points.push_back(make_pair(0, 2));
    int n = points.size();
    cout << mTC(points, 0, n-1);
	return 0;
}