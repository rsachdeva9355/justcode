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
	
	int n;
	cin >> n;

	while(n--) {
		int grade;
		cin >> grade;

		if (grade < 38) {
			cout << grade << endl;
		} else {
			if ((grade % 5) == 3) {
				grade += 2;
			} else if(grade % 5 == 4) {
				grade += 1;
			}
			cout << grade << endl;
		}
	}	
	return 0;
}