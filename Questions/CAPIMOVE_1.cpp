#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long arr[50010];

void printVector(std::vector<long> v) {
	cout << "Printing Vector " << endl;
	for (vector<long>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
} 

int main() {
	long t;
	long n;
	cin >> t;
	while(t--) {
		cin >> n;
		map< long, vector<long> > teleports;
		map<long, long> backtrack;
		for (long i = 0; i < n; i++) {
			cin >> arr[i];
			backtrack.insert(pair<long, long>(arr[i], i + 1));
		}
		for (long i = 0; i < n - 1; i++) {
			long a,b;
			cin >> a >> b;
			map< long, vector<long> >::iterator p = teleports.find(a);
			if (p != teleports.end()) {
				p->second.push_back(b);
			} else {
				vector<long> vec;
				vec.push_back(b);
				teleports.insert(pair< long, vector<long> >(a, vec));
			}

			p = teleports.find(b);
			if (p != teleports.end()) {
				p->second.push_back(a);
			} else {
				vector<long> vec;
				vec.push_back(a);
				teleports.insert(pair< long, vector<long> >(b, vec));
			}

		}
		sort(arr, arr + n);
		map< long, vector<long> >::iterator value;
		for (long i = 1; i <= n; i++) {
			value = teleports.find(i);
			if (value != teleports.end()) {
				vector<long> v = value -> second;
				// printVector(v);
				for (long j = n-1; j >= 0; j--) {	
					if ( i != j + 1) {
						if (find(v.begin(), v.end(), j + 1) == v.end()) {
							cout << backtrack.find(arr[j]) -> second << endl;
							break;
						}
					}
				}
			} else {
				if (i == n) {
					cout << backtrack.find(arr[n - 2]) -> second <<endl;
				} else {
					cout << backtrack.find(arr[n - 1]) -> second <<endl;
				}
			}
		}
	}

	return 0;
}