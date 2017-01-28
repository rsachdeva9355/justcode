#include<iostream>

using namespace std;

char W = 'W';
char A = 'A';
char B = 'B';
char arr[1000][1000];

bool areBoundariesBricks(int n, int m) {
	for (int i = 0; i < m; i+=(m - 1)) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i] != B) {
				return false;
			}
		}
	}
	for (int i = 1; i < m - 1; i++) {
		if (arr[n - 1][i] != B) {
			return false;
		}
	}

	return true;
}

string convert(bool a) {
	return a ? "yes" : "no";
}

bool isWaterStable(int i, int j) {
	// LEFT
	if (arr[i][j-1] == A) {
		return false;
	}

	// RIGHT
	if (arr[i][j+1] == A) {
		return false;
	}
	// UP
	if (i != 0) {
		if (arr[i - 1][j] == B) {
			return false;
		}
	}
	// DOWN
	if (arr[i + 1][j] == A) {
		return false;
	}
	return true;
}

bool isAirStable(int i, int j) {
		// LEFT
	if (arr[i][j-1] == W) {
		return false;
	}

	// RIGHT
	if (arr[i][j+1] == W) {
		return false;
	}
	// UP
	if (i != 0) {
		if (arr[i - 1][j] == B || arr[i - 1][j] == W) {
			return false;
		}
	}
	
	return true;
}

int main() {
	long t;
	int n,m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}	
		}
		bool stable = true;
		if (n == 1) {
			for (int j = 0; j < m; j++) {
				if (arr[0][j] == W) {
					stable = false;
					break;
				}
			}
			cout << convert(stable) << endl;
			continue;
		}
		if(areBoundariesBricks(n, m)) {
			for (int j = 1; j < m - 1; j++) {
				for (int i = 0; i < n - 1; i++) {
					if (arr[i][j] == W) {
						stable = isWaterStable(i,j);
					}
					if (arr[i][j] == A) {
						stable = isAirStable(i,j);
					}
					if (!stable) {
						break;
					}
				}
				if (!stable) {
					break;
				}
			}
			cout << convert(stable) << endl;
		} else {
			cout << "no" << endl;
		}
	}
}