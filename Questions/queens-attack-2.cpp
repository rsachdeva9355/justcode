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

#define QUEEN -2
#define OBS -1
#define N 0
#define S 1
#define E 2
#define W 3
#define NE 4
#define NW 5
#define SE 6
#define SW 7

int directionCount[8];

map< pair<int, int>, bool> obstacles;

void goNorth(int size, int qx, int qy) {
	int i = qx;
	int count = 0;
	for (int j = qy + 1; j <= size; j++) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}
	}
	directionCount[N] = count;
}

void goSouth(int size, int qx, int qy) {
	int i = qx;
	int count = 0;
	for (int j = qy - 1; j > 0; j--) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}
	}
	directionCount[S] = count;
}

void goEast(int size, int qx, int qy) {
	int j = qy;
	int count = 0;
	for (int i = qx + 1; i <= size; i++) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}
	}
	directionCount[E] = count;
}

void goWest(int size, int qx, int qy) {
	int j = qy;
	int count = 0;
	for (int i = qx - 1; i > 0; i--) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}
	}
	directionCount[W] = count;
}

void goNorthEast(int size, int qx, int qy) {
	int count = 0;
	int i = qx + 1, j = qy + 1;
	for (; i <= size && j <= size; i++, j++) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}	
	}
	directionCount[NE] = count;
}

void goSouthEast(int size, int qx, int qy) {
	int count = 0;
	int i = qx - 1, j = qy + 1;
	for (; i > 0 && j <= size; i--, j++) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}
	}
	directionCount[SE] = count;
}

void goNorthWest(int size, int qx, int qy) {
	int count = 0;
	int i = qx - 1, j = qy - 1;
	for (; i > 0 && j > 0; i--, j--) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}	
	}
	directionCount[NW] = count;
}

void goSouthWest(int size, int qx, int qy) {
	int count = 0;
	int i = qx + 1, j = qy - 1;
	for (; i <= size && j > 0; i++, j--) {
		if (obstacles.find(make_pair(i, j)) != obstacles.end()) {
			break;
		} else {
			count++;
		}	
	}
	directionCount[SW] = count;
}

int main() {
	int size, queries;
	cin >> size >> queries;
	int qx, qy;
	cin >> qx >> qy;
	while(queries--) {
		int x, y;
		cin >> x >> y;
		obstacles.insert(make_pair(make_pair(x, y), true));
	}
	goNorth(size, qx, qy);
	goSouth(size, qx, qy);
	goNorthEast(size, qx, qy);
	goNorthWest(size, qx, qy);
	goSouthEast(size, qx, qy);
	goSouthWest(size, qx, qy);
	goEast(size, qx, qy);
	goWest(size, qx, qy);

	long count = 0;
	for (int i = 0; i < 8; i++) {
		count += directionCount[i];
	}
	cout << count << endl;
	return 0;
}