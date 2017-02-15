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

bool isSubSequence(string str1, string str2, int m, int n)
{
    if (m == 0) return true;
    if (n == 0) return false;
 
    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);
 
    return isSubSequence(str1, str2, m, n-1);
}

int main() {
	long t;
	cin >> t;
	string hr = "hackerrank";
	while(t--) {
		string in;
		cin >> in;
		if (isSubSequence(hr, in, hr.length(), in.length())) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}