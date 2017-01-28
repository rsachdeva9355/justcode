#include<iostream>

using namespace std;

int main() {

	long t;
	long c, d, l;
	cin >> t;

	while (t--) {
		cin >> c >> d >> l;
		long a = c - d;
		if (c - d < 0) {
			a = d - c;
		}
		if ( l % 4 == 0 && (l <= ((c + d) * 4) && l >= (a * 4))) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}